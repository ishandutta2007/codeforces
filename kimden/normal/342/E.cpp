#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<int> e;
vector<vector<pii>> g;
vector<vector<int>> anc_cd;
vector<int> par_cd;
vector<int> sz;
vector<int> h;
vector<vector<int>> anc_tree;
int cd_root;
vector<multiset<int>> s;

void dfs(int v, int prv = -1){
    sz[v] = 1;
    for(auto p: g[v]){
        if(!e[p.second] && p.first != prv){
            dfs(p.first, v);
            sz[v] += sz[p.first];
        }
    }
}

int find_centroid(int v){
    dfs(v);
    int total_size = sz[v];
    int prv = -1;
    while(1){
        int max_size = -1;
        int to = -1;
        for(auto p: g[v]){
            if(!e[p.second] && p.first != prv){
                if(sz[p.first] > total_size / 2 && sz[p.first] > max_size){
                    max_size = sz[p.first];
                    to = p.first;
                }
            }
        }
        if(to == -1){
            return v;
        }
        prv = v;
        v = to;
    }
}

void centroid_decomp(int v = 0, int prv = -1) {
    int c = find_centroid(v);
    if(prv == -1){
        cd_root = c;
    }
    par_cd[c] = prv;
    if(prv >= 0){
        anc_cd[c].push_back(prv);
    }
    if(prv >= 0){
        for(int i = 0; i < anc_cd[anc_cd[c][i]].size(); ++i){
            anc_cd[c].push_back(anc_cd[anc_cd[c][i]][i]);
        }
    }
    for(pii p: g[c]){
        if(!e[p.second]){
            e[p.second] = 1;
            centroid_decomp(p.first, c);
        }
    }
}

void dfs_h(int v = 0, int prv = -1){
    if(prv == -1){
        h[v] = 0;
    }
    for(auto p: g[v]){
        int u = p.first;
        if(u != prv){
            h[u] = h[v] + 1;
            anc_tree[u].push_back(v);
            for(int i = 0; i < anc_tree[anc_tree[u][i]].size(); ++i){
                anc_tree[u].push_back(anc_tree[anc_tree[u][i]][i]);
            }
            dfs_h(u, v);
        }
    }
}

int lca(int u, int v){
    if(h[u] > h[v]){
        for(int i = (int)anc_tree[u].size() - 1; i >= 0; --i){
            if(h[u] - h[v] >= (1 << i)){
                u = anc_tree[u][i];
                i = min(i, (int)anc_tree[u].size());
            }
        }
    }
    if(h[v] > h[u]){
        for(int i = (int)anc_tree[v].size() - 1; i >= 0; --i){
            if(h[v] - h[u] >= (1 << i)){
                v = anc_tree[v][i];
                i = min(i, (int)anc_tree[v].size());
            }
        }
    }
    if(u == v){
        return u;
    }
    for(int i = (int)anc_tree[u].size() - 1; i >= 0; --i){
        if(anc_tree[u][i] != anc_tree[v][i]){
            u = anc_tree[u][i];
            v = anc_tree[v][i];
            i = min(i, (int)anc_tree[u].size());
        }
    }
    return anc_tree[u][0];
}

int dist(int u, int v){
    return h[u] + h[v] - 2 * h[lca(u, v)];
}

void red(int x){
    for(int cur = x; 1; cur = par_cd[cur]){
        s[cur].insert(dist(x, cur));
        if(cur == cd_root){
            break;
        }
    }
}

int get(int x){
    int ans = 1'000'000'000;
    for(int cur = x; 1; cur = par_cd[cur]){
        if(!s[cur].empty()){
            ans = min(ans, (*s[cur].begin()) + dist(x, cur));
        }
        if(cur == cd_root){
            break;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    e.resize(n - 1, 0);
    par_cd.resize(n);
    anc_cd.resize(n);
    anc_tree.resize(n);
    g.resize(n);
    sz.resize(n);
    s.resize(n);
    h.resize(n);
    for(int i = 0; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    dfs_h();
    centroid_decomp();
    red(0);
    for(int i = 0; i < m; ++i){
        int t, x;
        cin >> t >> x;
        --x;
        if(t == 1){
            red(x);
        }else{
            cout << get(x) << endl;
        }
    }



    return 0;
}