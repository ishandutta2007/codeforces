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
#define endl "\n"
#define eb emplace_back
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
int nx[25][maxN];
int sub[maxN];
int h[maxN];

void dfs(int node, int par){
    h[node] = h[par] + 1;
    sub[node] = 1;
    nx[0][node] = par;
    for(int cc : vc[node]){
        if(cc != par){
            dfs(cc, node);
            sub[node] += sub[cc];
        }
    }
}

inline void rise(int &x, int val){
    int paw = 0;
    while(val){
        paw += __builtin_ctz(val);
        val >>= (__builtin_ctz(val));
        x = nx[paw][x];
        val ^= 1;
    }
}

inline int solve_god(int x, int y){
    if(h[x] < h[y]) swap(x, y);
    rise(x, h[x] - h[y]);
    if(x == y) return y;
    for2(i, 19, 0){
        if(nx[i][x] != nx[i][y]){
            x = nx[i][x];
            y = nx[i][y];
        }
    }
    return nx[0][x];
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 2, n){
        cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    dfs(1, 1);
    for1(ds, 0, 20){
        for1(i, 1, n){
            nx[ds + 1][i] = nx[ds][nx[ds][i]];
            // cout << nx[ds][i] << " ";
        }
        // cout << endl;
    }
    // cout << solve_god(2, 4) << endl;
    // return 0;
    int o; cin >> o; while(o--){
        cin >> x >> y;
        if(x == y){
            cout << n << endl;
            continue;
        }
        if((h[x] + h[y]) % 2){
            cout << "0\n"; continue;
        }
        z = solve_god(x, y);
        //cout << z << endl;
        if(h[x] == h[y]){
            int skip = h[x] - h[z] - 1;
            rise(x, skip);
            rise(y, skip);
            cout << n - sub[x] - sub[y] << endl;
        }
        else{
            if(h[x] < h[y]) swap(x, y);
            int ds = (h[x] + h[y] - 2 * h[z]) / 2;
            y = x;
            rise(x, ds);
            rise(y, ds - 1);
            cout << sub[x] - sub[y] << endl;
        }
    }

}