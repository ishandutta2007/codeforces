#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


int n, m, s;
int cnt = 0;
int cmp = 0;
vector<vector<int>> g, gt;
vector<int> tout, mkd1, mkd2, comp;
vector<int> e1, e2;
vector<int> order;

void dfs(int v){
    mkd1[v] = 1;
    for(auto u: g[v]){
        if(!mkd1[u]){
            dfs(u);
        }
    }
    tout[v] = cnt++;
    order.push_back(v);
}

void dfs2(int v){
    if(comp[v] == -1){
        comp[v] = cmp++;
    }
    mkd2[v] = 1;
    for(auto u: gt[v]){
        if(!mkd2[u]){
            comp[u] = comp[v];
            dfs2(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    cin >> n >> m >> s;
    --s;
    int a, b;
    g.resize(n);
    gt.resize(n);
    tout.resize(n);
    mkd1.resize(n, 0);
    mkd2.resize(n, 0);
    comp.resize(n, -1);
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        --a;
        --b;
        e1.push_back(a);
        e2.push_back(b);
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    for(int i = 0; i < n; ++i){
        if(!mkd1[i]){
            dfs(i);
        }
    }
    while(!order.empty()){
        int i = order.back();
        if(!mkd2[i]){
            dfs2(i);
        }
        order.pop_back();
    }
    vector<int> freecomp(cmp, 1);
    for(int i = 0; i < m; ++i){
        if(comp[e1[i]] != comp[e2[i]])
            freecomp[comp[e2[i]]] = 0;
    }
    int ans = 0;
   // cerr << comp[s] << endl;
    for(int i = 0; i < cmp; ++i){
        //cerr << i << " " << freecomp[i] << endl;
        if(freecomp[i] && i != comp[s]){
            ++ans;
        }
    }
    cout << ans << endl;



}