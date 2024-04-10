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
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
set<int> vc[maxN];
int id[maxN];
int fib[maxN];

int sub[maxN];
int par[maxN];

void output(bool bk){
    if(bk) cout << "YES\n";
    else cout << "NO\n";
    exit(0);
}

void dfs_sub(int node, int pare, vector<int> &dumb){
    par[node] = pare;
    sub[node] = 1;
    dumb.pb(node);
    for(int child : vc[node]){
        if(child == pare) continue;
        dfs_sub(child, node, dumb);
        sub[node] += sub[child];
    }
    return;
}

void dfs_com(int root){
    vector<int> dumb;
    dfs_sub(root, 0, dumb);
    int ind = id[sub[root]];
    if(ind < 3) return;
    x = fib[ind - 1];
    y = fib[ind - 2];
    for(int nd : dumb){
        if(sub[nd] == x || sub[nd] == y){
            x = nd; y = par[nd];
            vc[x].erase(y);
            vc[y].erase(x);
            dfs_com(y);
            dfs_com(nd);
            return;
        }
    }
    output(0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    fib[1] = 1;
    fib[2] = 2;
    memset(id, 0, sizeof(id));
    for1(i, 3, 300){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for1(i, 1, 26){
        id[fib[i]] = i;
    }
    if(!id[n]) output(0);
    for1(i, 2, n){
        cin >> x >> y;
        vc[x].insert(y);
        vc[y].insert(x);
    }
    dfs_com(1);
    output(1);
}