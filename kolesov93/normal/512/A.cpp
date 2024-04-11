#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acos(-1.);
const int N = 222;

int a[N][N];
int b[N][N];
string w[N];
int d[N];

int order[N], k;
int was[N];



int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (i != 0) {
            int lim = min(w[i].size(), w[i - 1].size());
            bool done = false;
            for (int j = 0; j < lim; ++j)
                if (w[i - 1][j] != w[i][j]) {
                    a[ w[i - 1][j] - 'a' ][ w[i][j] - 'a' ] = 1;
                    b[ w[i - 1][j] - 'a' ][ w[i][j] - 'a' ] = 1;
                    done = true;
                    break;
                }
            if (!done && w[i].size() <= w[i - 1].size()) {
                puts("Impossible");
                return 0;
            }
        }
    }

    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            if (b[i][j] == 0) b[i][j] = 1e7;
    for (int k = 0; k < 26; ++k)
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                b[i][j] = min(b[i][j], b[i][k] + b[k][j]);

    for (int i = 0; i < 26; ++i)
        for (int j = i + 1; j < 26; ++j)
            if (b[i][j] < 100 && b[j][i] < 100) {
                puts("Impossible");
                return 0;
            }

    queue<int> q;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            d[i] += a[j][i];
        }
        if (d[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front(); q.pop();
        cout << char(x + 'a');
        for (int i = 0; i < 26; ++i)
            if (a[x][i])  {
                d[i]--;
                if (d[i] == 0) q.push(i);
            }
    }
    cout << endl;
    
    return 0;
}