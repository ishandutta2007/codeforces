#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <string>
#include <cstring>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = acos(-1.);
const int N = 141;
const int M = N / 2;
char w[N][N];
char s[N][N];
char res[N][N];


int main() {
    int n;
    scanf("%d\n", &n);

    typedef pair<int, int> pii;
    vector<pii> fig, war, peace;
    for (int i = 0; i < n; ++i) {
        scanf("%s", w[i]);
        for (int j = 0; j < n; ++j)
            if (w[i][j] == 'o') fig.emplace_back(i, j);
            else if (w[i][j] == 'x') war.emplace_back(i, j);
            else peace.emplace_back(i, j);
    }

    int cx = M, cy = M;
    memset(res, 'x', sizeof(res));
    res[cx][cy] = 'o';
    for (auto f : fig)
        for (auto p : peace) {
            res[cx + p.first - f.first][cy + p.second - f.second] = '.';
        }
    vector<pii> steps;
    for (int dx = -n; dx <= n; ++dx)
        for (int dy = -n; dy <= n; ++dy)
            if (res[cx + dx][cy + dy] == 'x') steps.emplace_back(dx, dy);

    memset(s, '.', sizeof(s));
    for (auto f : fig) {
        for (auto step : steps) {
            int nx = f.first + step.first;
            int ny = f.second + step.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) s[nx][ny] = 'x';
        }
    }
    for (auto f : fig) s[f.first][f.second] = 'o';

    bool cool = true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (s[i][j] != w[i][j]) {
                cool = false;
                break;
            }

    if (!cool) {
        puts("NO");
        return 0;
    }

    puts("YES");
    for (int dx = -n + 1; dx < n; ++dx) {
        for (int dy = -n + 1; dy < n; ++dy) putchar(res[cx + dx][cy + dy]);
        puts("");
    }


    return 0;
}