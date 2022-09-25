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
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 2222;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
int ans;
vector<int> e[maxn], g[maxn];
bool used[maxn];
int in[maxn], out[maxn], tmr;
int curColor, c[maxn], compSize[maxn], compSizeCnt[maxn], cnt[maxn];

void dfs1(int v, int p) {
    used[v] = 1;
    in[v] = out[v] = tmr++;
    for (int i = 0; i < (int)e[v].size(); i++) {
        int to = e[v][i];
        if (to == p) continue;
        if (used[to]) {
            out[v] = min(out[v], in[to]);
        } else {
            dfs1(to, v);
            out[v] = min(out[v], out[to]);
        }
    }
}

void dfs2(int v, int cc) {
    c[v] = cc;
    cnt[cc]++;
    for (int i = 0; i < (int)e[v].size(); i++) {
        int to = e[v][i];
        if (c[to] == 0) {
            if (out[to] == in[to]) {
                curColor++;
                g[cc].push_back(curColor);
                g[curColor].push_back(cc);                
                dfs2(to, curColor);
            } else {
                dfs2(to, cc);
            }
        }
    }
}

int dp[maxn];

void dfs3(int v, int p) {
    compSize[v] = 1;
    compSizeCnt[v] = cnt[v];
    dp[v] = 0;
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to = g[v][i];
        if (to == p) continue;
        dfs3(to, v);
        dp[v] += dp[to] + compSizeCnt[to] * cnt[v];
        compSize[v] += compSize[to];
        compSizeCnt[v] += compSizeCnt[to];
    }
}

int dfs4(int v, int p) {
    for (int i = 0; i < (int)g[v].size(); i++) {
        if (g[v][i] == p) continue;
        if (compSizeCnt[g[v][i]] * 2 >= n) {
            return dfs4(g[v][i], v);
        }
    }
    return v;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            e[i].clear();
            g[i].clear();
            cnt[i] = 0;
            //for (int j = 1; j <= n; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = 0; // k = 0 -> from; k = 1 -> to
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        memset(used, 0, sizeof(used));
        dfs1(1, -1);
        memset(c, 0, sizeof(c));
        curColor = 1;
        dfs2(1, 1);
        
        ans = 0;
        for (int i = 1; i <= curColor; i++) ans += cnt[i] * cnt[i];
        dfs3(1, -1);
        int v = dfs4(1, -1);
        dfs3(v, -1);
        vector<int> can(n + 1, 0);
        can[0] = 1;
        for (int i = 0; i < (int)g[v].size(); i++) {
            for (int j = n; j >= 0; j--) {
                if (can[j]) {
                    can[j + compSizeCnt[g[v][i]]] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < (int)g[v].size(); i++) ans += dp[g[v][i]];
        
        for (int i = 0; i <= n; i++) {
            if (can[i]) {
                res = max(res, i * (n - i - cnt[v]) + (n - cnt[v]) * cnt[v]);
            }
        }
        ans += res;
        
        cout << ans << endl;
    }
    
    return 0;
}