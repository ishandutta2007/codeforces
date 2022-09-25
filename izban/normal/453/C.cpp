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

const int maxn = 200200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
vector<int> e[maxn];
vector<int> ans;
bool vis[maxn];
bool f[maxn];

void dfs(int v, int p = -1) {
    vis[v] = true;
    ans.push_back(v);
    f[v] ^= 1;
    for (int i = 0; i < (int)e[v].size(); i++) if (e[v][i] != p && !vis[e[v][i]]) {
        dfs(e[v][i], v);
        ans.push_back(v);
        f[v] ^= 1;
    }
    if (f[v]) {
        if (p != -1) {
            ans.push_back(p);
            f[p] ^= 1;
            ans.push_back(v);
            f[v] ^= 1;
        } else {
            ans.pop_back();
            f[v] ^= 1;
        }
    }
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
            vis[i] = false;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) cin >> f[i];
        
        bool was = 0;
        ans.clear();
        for (int i = 1; i <= n; i++) if (f[i]) {
            was = 1;
            dfs(i);
            bool ok = true;
            for (int j = 1; j <= n; j++) {
                ok &= !f[j];
            }
            if (ok) {
                cout << (int)ans.size() << endl;
                for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
            } else {
                cout << -1 << endl;
            }
            break;
        }
        if (!was) cout << 0 << endl;
    }
    
    return 0;
}