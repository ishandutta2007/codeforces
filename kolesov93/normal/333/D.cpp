#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string.h>
#include <string>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int N = 1111;

struct cell {
    int x, y, val;


    cell(int ax = 0, int ay = 0, int aval = 0) 
        : x(ax)
        , y(ay)
        , val(aval)
    {}

    bool operator <(const cell& A) const {
        return val > A.val; 
    }
};

vector<cell> a;

vector<int> havenum[N];

bool matched[N][N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int x; scanf("%d", &x);
            a.push_back(cell(i, j, x));
        }
    sort(a.begin(), a.end());

    for (int q = 0; q < a.size(); ++q) {
        int x = a[q].x, y = a[q].y;

        for (int i = 0; i < havenum[y].size(); ++i)
            if (matched[x][ havenum[y][i] ]) {
                cout << a[q].val << endl;
                return 0;
            } else {
                matched[x][ havenum[y][i] ] = matched[ havenum[y][i] ][x] = true;
            }

        havenum[y].push_back(x);
    }

    return 0;
}