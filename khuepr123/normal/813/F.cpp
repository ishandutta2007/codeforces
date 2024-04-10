/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
// #define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int m;
int ans[maxN];
int cnter = 0;

map<ii, int> mp;
vector<ii> tree[maxN * 4];
int l[maxN * 4];
int r[maxN * 4];

int id;
int istrue = 1;

int par[maxN * 2];

struct revert{
    int &x , y, id;
    revert(int &x, int y, int id): x(x), y(y), id(id) {}
};

vector<revert> stk;
inline void deduce(){
    while(1){
        auto pr = stk.back();
        if(pr.id == id){
            pr.x = pr.y;
            stk.pop_back();
        }
        else break;
    }
}

int root(int i){
    if(par[i] == -1) return i ^ 1;
    int vl = root(par[i]) ^ 1;
    stk.pb({par[i], par[i], id});
    return par[i] = vl;
}

void unite(int i, int j){
    if(!istrue) return;
    i = root(i * 2);
    j = root(j * 2);
    if(i == j){
        istrue = 0;
        stk.pb({istrue, 1, id});
        return;
    }
    if((i & 1) && (j & 1)){
        i ^= 1;
        j ^= 1;
    }
    if(i & 1) swap(i, j);
    if(i + 1 == j) return;
    stk.pb({par[i], par[i], id});
    par[i] = j;
}

void build(int node, int left, int right){
    l[node] = left;
    r[node] = right;
    if(left == right) return;
    int mid = (left + right) / 2;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);
}

void update(int node, int left, int right){
    if(left > right) return;
    if(left == l[node] && right == r[node]){
        tree[node].pb(ii(x, y));
        return;
    }
    int mid = r[node * 2];
    update(node * 2, left, min(mid, right));
    update(node * 2 + 1, max(left, mid + 1), right);
}

void dfs(int node){
    id = node;
    for(ii child : tree[node]) unite(child.fi, child.se);
    if(l[node] == r[node]){
        ans[++cnter] = istrue;
    }
    else{
        dfs(node * 2);
        dfs(node * 2 + 1);
    }
    id = node;
    deduce();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    build(1, 1, m);
    stk.pb({x, 0, -1});
    for1(i, 1, m){
        cin >> x >> y;
        ii pr = ii(x, y);
        if(mp.find(pr) == mp.end()) mp[pr] = i;
        else{
            update(1, mp[pr], i - 1);
            mp.erase(pr);
        }
    }
    for1(i, 1, n){
        par[i * 2] = -1;
        par[i * 2 + 1] = i * 2;
    }
    for(auto child : mp){
        x = child.fi.fi;
        y = child.fi.se;
        update(1, child.se, m);
    }
    dfs(1);
    for1(i, 1, m){
        if(ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
    cout << endl;
}