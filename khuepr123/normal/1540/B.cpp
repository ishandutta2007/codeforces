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
vector<int> vc[maxN];
int dp[205][205];
int pw[maxN];
int inv2;
int invn;

int poow(int num, int coef){
    int res = 1;
    while(coef){
        if(coef & 1) res = (res * num) % mod;
        num = (num * num) % mod;
        coef >>= 1;
    }
    return res;
}

int targ, root;
int dist;
int ds[maxN];
bool mark[maxN];

void dfs_cum(int node, int par){
    ds[node] = ds[par] + 1;
    if(node == targ){
        dist = ds[node];
        mark[node] = 1;
    }
    for(int child : vc[node]){
        if(child == par) continue;
        dfs_cum(child, node);
        mark[node] |= mark[child];
    }
}

void dfs_real(int node, int par){
    if(mark[node] == 0) ds[node] = ds[par];
    for(int child : vc[node]){
        if(child == par) continue;
        dfs_real(child, node);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    pw[0] = 1;
    inv2 = (mod + 1) / 2;
    for1(i, 1, maxN - 1){
        pw[i] = pw[i - 1] * 2;
        pw[i] %= mod;
    }
    cin >> n;
    invn = poow(n, mod - 2);
    for1(i, 2, n){
        cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    for1(i, 0, n){
        for1(j, 0, n){
            if(i == 0 && j == 0) continue;
            else if(i == 0) dp[i][j] = 1;
            else if(j == 0) dp[i][j] = 0;
            else{
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * inv2;
                dp[i][j] %= mod;
            }
        }
    }
    // dp[i][j] mean path i j with objective i win
    ds[0] = -1;
    int ans = 0;
    for1(lar, 2, n){
        for1(sml, 1, lar - 1){
            memset(mark, 0, sizeof(mark));
            root = sml;
            targ = lar;
            dfs_cum(root, 0);
            dfs_real(root, 0);
            int sam = 0;
            for1(i, 1, n){
                ans += dp[dist - ds[i]][ds[i]];
            }
            ans %= mod;
        }
    }
    ans *= invn;
    ans %= mod;
    cout << (ans + mod) % mod << endl;
}