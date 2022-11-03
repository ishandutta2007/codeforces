#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;

//const ll mod = 1000000007;
//const ld eps = 1e-8;
const int MAXN = 2002;
const int neg = 2048;

vector<vector<int>> g;
vector<vector<int>> gt;
vector<int> out;
vector<int> tout;
int timer = 0;
vector<int> parent;
vector<int> sz;
vector<char> mkd;

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if(parent[v] == v){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u != v){
        if(sz[u] < sz[v]){
            swap(u, v);
        }
        sz[u] += sz[v];
        parent[v] = u;
    }
}

void dfs(int v){
    mkd[v] = 1;
    for(auto u: g[v]){
        if(!mkd[u]) {
            dfs(u);
        }
    }
    out.push_back(v);
    tout[v] = out.size();
}

void dfs2(int v){
    mkd[v] = 1;
    for(auto u: gt[v]){
        if(!mkd[u]) {
            union_sets(u, v);
            dfs2(u);
        }
    }

}

int main() {
    int ttt = 1;
//    cin >> ttt;
    int n, m;
    int a, b, c;
    for(int tt = 0; tt < ttt; ++tt){
        vector<int> cities;
//        cout << "Scenario " << tt + 1 << ":" << endl;
        cin >> n >> m;
        g.clear();
        gt.clear();
        out.clear();
        mkd.clear();
        parent.clear();
        sz.clear();
        tout.clear();
        g.resize(n ^ neg, vector<int>());
        gt.resize(n ^ neg, vector<int>());
        parent.resize(n ^ neg, -1);
        sz.resize(n ^ neg, -1);
        mkd.resize(n ^ neg, 0);
        tout.resize(n ^ neg, -1);
        timer = 0;
        for(int i = 0; i < m; ++i){
            cin >> a >> b >> c;
            a--;
            b--;
            if(c == 1){
                g[a ^ neg].push_back(b ^ neg);
                g[b ^ neg].push_back(a ^ neg);
                g[a].push_back(b);
                g[b].push_back(a);
                gt[a ^ neg].push_back(b ^ neg);
                gt[b ^ neg].push_back(a ^ neg);
                gt[a].push_back(b);
                gt[b].push_back(a);
            }else{
                g[a ^ neg].push_back(b);
                g[b ^ neg].push_back(a);
                g[a].push_back(b ^ neg);
                g[b].push_back(a ^ neg);

                gt[a ^ neg].push_back(b);
                gt[b ^ neg].push_back(a);
                gt[a].push_back(b ^ neg);
                gt[b].push_back(a ^ neg);
            }
        }
        for(int i = 0; i < n; ++i){
            make_set(i);
            if(!mkd[i]){
                dfs(i);
            }
        }
        for(int i = 0; i < n; ++i){
            make_set(i ^ neg);
            if(!mkd[neg ^ i]){
                dfs(neg ^ i);
            }
        }
        mkd.clear();
        mkd.resize(n ^ neg, 0);
        while(!out.empty()){
            int v = out.back();
            if(!mkd[v]){
                dfs2(v);
            }
            out.pop_back();
        }
        bool ans = true;
        for(int i = 0; i < n; ++i){
            int s1 = find_set(i);
            int s2 = find_set(i ^ neg);
            if(s1 == s2){
                ans = false;
                break;
            }
            if(tout[s1] < tout[s2]){
                cities.push_back(i);
            }
        }
        if(!ans){
            cout << "Impossible" << endl;
        }else {
            cout << cities.size() << endl;
            for(int j = 0; j < cities.size(); j++){
                if(j){
                    cout << " ";
                }
                cout << cities[j] + 1;
            }
            cout << endl;
        }
    }
}