/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define iii pair<int, ii>
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

// add to the subtree
int sub[maxN];
int addled = 0;
set<int> st;
int par[maxN];

int h[maxN];
int find(int i){
    if(i == par[i]) return i;
    else return par[i] = find(par[i]);
}

vector<iii> ed;
vector<ii> trash;
vector<int> vc[maxN];
vector<int> qry[maxN];

void dfs_hei(int node, int pare){
    sub[node] = 0; a[node] = 0;
    h[node] = h[pare] + 1;
    for(int cc : vc[node]) if(cc != pare)
        dfs_hei(cc, node);
}

void locomize(int node, int val = 1){
    sub[node] += val;
}

int ochii[maxN];
void dfs_qry(int node, int pare){
    st.insert(node);
    for(int cc : qry[node]){
        locomize(node);
        if(st.find(cc) == st.end()) locomize(cc);
        else{
            ++addled; locomize(ochii[cc], -1);
        }
    }
    for(int cc : vc[node]) if(cc != pare){
        ochii[node] = cc;
        dfs_qry(cc, node);
    }
    st.erase(node);
}

void dfs_add(int node, int pare){
    a[node] += sub[node];
    a[node] += addled;
    for(int cc : vc[node]) if(cc != pare){
        sub[cc] += sub[node];
        dfs_add(cc, node);
    }
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> z;
    memset(a, 0, sizeof(a));
    memset(sub, 0, sizeof(sub));
    for1(i, 1, z){
        cin >> x >> y;
        ed.pb({i, ii(x, y)});
    }
    sort(all(ed));
    for1(i, 1, n) par[i] = i;
    for(auto cac : ed){
        x = cac.se.fi; y = cac.se.se; z = cac.fi;
        if(find(x) != find(y)){
            par[find(x)] = find(y);
            vc[x].pb(y);
            vc[y].pb(x);
        }
        else trash.pb(ii(x, y));
    }
    h[0] = 0;
    dfs_hei(1, 0);
    for(ii &pr : trash){
        if(h[pr.fi] < h[pr.se]) swap(pr.fi, pr.se);
        qry[pr.fi].pb(pr.se);
    }
    dfs_qry(1, 0);
    dfs_add(1, 0);
    for1(i, 1, n) cout << (a[i] == trash.size());
}