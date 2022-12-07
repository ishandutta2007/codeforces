#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

using namespace std;

const int N = 111111;
char w[N * 5];
vector<int> g[N];
string s[N];
int n, need, p[N * 10];
int ans = 0;

void dfs(int x, int pos) {
    for (int q = 0; q < g[x].size(); ++q) {
        int y = g[x][q];

        for (int ps = 0; ps < s[y].size(); ++ps) {
            int i = pos + ps;
            w[i] = s[y][ps];

            int& k = p[i] = p[i - 1];
            while (k && w[i] != w[k]) k = p[k - 1];
            if (w[i] == w[k]) {
                ++k;
            }

            if (k == need) {
                ++ans;
            }
        }

        dfs(y, pos + s[y].size());
    }
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        int f;
        scanf("%d ", &f);
        g[f].push_back(i);
        gets(w);
        s[i] = w;
    }

    gets(w);
    need = strlen(w);
    
    w[need] = '$';
    for (int i = 1; i <= need; ++i) {
        int& k = p[i] = p[i - 1];
        while (k && w[i] != w[k]) k = p[k - 1];
        if (w[i] == w[k]) {
            ++k;
        }
    }

    dfs(1, need + 1);

    cout << ans << endl;

    return 0;
}