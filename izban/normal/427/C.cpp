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

int n, m;
int c[maxn];
vector<int> e[maxn], g[maxn], vct;
bool vis[maxn];

void dfs1(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    for (int i = 0; i < e[v].size(); i++) {
        dfs1(e[v][i]);
    }
    vct.push_back(v);
}

int curmn, cnt;

void dfs2(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    if (c[v] < curmn) {
        curmn = c[v];
        cnt = 0;
    }
    cnt += c[v] == curmn;
    for (int i = 0; i < g[v].size(); i++) dfs2(g[v][i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) {
        vct.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
            e[i].clear();
            g[i].clear();
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) vis[i] = 0;
        for (int i = 1; i <= n; i++) if (!vis[i]) dfs1(i);
        for (int i = 1; i <= n; i++) vis[i] = 0;
        
        reverse(vct.begin(), vct.end());
        ll ans1 = 0, ans2 = 1;
        for (int i = 0; i < n; i++) {
            if (vis[vct[i]]) continue;
            curmn = 2e9;
            cnt = 0;
            dfs2(vct[i]);
            ans1 += curmn;
            ans2 = 1LL * ans2 * cnt % mod;
        }
        cout << ans1 << " " << ans2 << endl;
    }

	return 0;
}