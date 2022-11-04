#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n;
vvi g, g1;
vi c;
vi sz;
int am = 0;
void dfs1(int v, int p) {
    if(c[v] == 1) {
        ++sz[v];
    }
    for(int u : g[v]) {
        if(u == p) continue;
        dfs1(u, v);
        sz[v] += sz[u];
    }
}

void dfs2(int v, int p) {
    for(int u : g[v]) {
        if(u == p) continue;
        if(sz[u] > 1 || c[u] == 1) {
            g1[u].push_back(v);
        }
        if(am - sz[u] > 1 || c[v] == 1) {
            g1[v].push_back(u);
        }
        dfs2(u, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    g.resize(n);
    c.resize(n);
    g1.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        if(c[i] == 1) ++am;
    }
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    sz.assign(n, 0);
    dfs1(0, -1);
    dfs2(0, -1);
    vi dst(n, inf);
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(c[i] == 1) {
            dst[i] = 0;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int u : g1[v]) {
            if(dst[u] == inf) {
                dst[u] = dst[v] + 1;
                q.push(u);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(dst[i] != inf) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }

}