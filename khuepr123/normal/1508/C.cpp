/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define iii pair<int, ii>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int m;

vector<int> vc[maxN];
int par[maxN];
int par2[maxN];
set<int> remain;
int god;

int find(int i){
    if(i == par[i]) return i;
    return par[i] = find(par[i]);
}

bool unite(int i, int j){
    i = find(i); j = find(j);
    if(i == j) return 0;
    par[i] = j; return 1;
}
int find2(int i){
    if(i == par2[i]) return i;
    return par2[i] = find2(par2[i]);
}

bool unite2(int i, int j){
    i = find2(i); j = find2(j);
    if(i == j) return 0;
    par2[i] = j; return 1;
}


int rem;
int leaf;

void dfs_span(int node){
    remain.erase(node);
    int v = 0;
    while(1){
        auto it = remain.lower_bound(v);
        if(it == remain.end()) break;
        v = *it;
        if(!binary_search(vc[node].begin(), vc[node].end(), v)){
            unite(node, v);
            dfs_span(v);
            --rem;
        }
        ++v;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m; rem = (n * (n - 1)) / 2 - m; leaf = 0;
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    vector<iii> pov;
    for1(i, 1, m){
        cin >> x >> y >> z;
        leaf ^= z;
        vc[y].pb(x);
        vc[x].pb(y);
        pq.push({z, {x, y}});
    }
    for1(i, 1, n){
        remain.insert(i);
        sort(vc[i].begin(), vc[i].end());
        par[i] = i;
        par2[i] = i;
    }
    for1(i, 1, n){
        if(remain.find(i) != remain.end()){
            dfs_span(i);
        }
    }
    int ans = 0;
    if(rem) leaf = 0;
    while(!pq.empty()){
        auto tt = pq.top(); pq.pop();
        x = tt.se.se;
        y = tt.se.fi;
        z = tt.fi;
        if(unite(x, y)){
            ans += z;
            unite2(x, y);
        }
        else{
            pov.pb(tt);
        }
    }
    for(auto tt : pov){
        x = tt.se.se;
        y = tt.se.fi;
        z = tt.fi;
        if(find2(x) != find2(y)) leaf = min(leaf, z);
    }
    cout << ans + leaf << endl;
}