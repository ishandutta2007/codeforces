#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n;
int h[maxn], a[maxn], b[maxn];
vector<int> e[maxn], ans;

/*void dfs(int v, int ch, int p = -1) {
    h[v] = ch;
    for (int i = 0; i < (int)e[v].size(); i++) if (e[v][i] != p) dfs(e[v][i], ch + 1, v);
}*/

void dfs(int v, int h1, int h2, int p = -1) {
    if (h1 != a[v]) {
        h1 ^= 1;
        ans.push_back(v);
    }
    for (int i = 0; i < (int)e[v].size(); i++) if (e[v][i] != p) dfs(e[v][i], h2, h1, v);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            e[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
        for (int i = 1; i <= n; i++) a[i] ^= b[i];
        
        dfs(1, 0, 0);
        /*dfs(1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < e[i].size(); j++) {
                int to = e[i][j];
                for (int k = 0; k < e[to].size(); k++) {
                    g[i].push_back(e[to][k]);
                }
            }
        }
        dfs2(1);
        for (int i = 0; i < e[1].size(); i++) dfs2(e[1][i]);*/
        sort(ans.begin(), ans.end());
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
    }

	return 0;
}