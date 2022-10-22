/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
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
int n, dg[maxN];
int x, y, z, k;
int a[maxN];

vector<int> vc[maxN];
vector<int> vc2[maxN];

bool used[maxN];
bool ans[maxN];
int ord;

void dexout(){
    map<int, int> mp;
    x = 0;
    for1(i, 1, n){
        cin >> dg[i]; mp[dg[i]] = 0;
    }
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        itr->se = ++x;
    }
    for1(i, 1, n){
        // cout << dg[i] << " ";
        x = mp[dg[i]];
        // cout << x << " ";
        a[x] = i;
    }
    // cout << endl;
    for1(i, 2, n){
         vc[a[i]].pb(a[i - 1]);
        vc2[a[i - 1]].pb(a[i]);
    }
}

void dfs_chim(int nd){
    used[nd] = 1;
    for(int cc : vc[nd]) if(!used[cc]){
        dfs_chim(cc);
    }
    ord = nd;
}

void dfs_done(int nd){
    ans[nd] = 1;
    for(int cc : vc2[nd]) if(!ans[cc]){
        dfs_done(cc);
    }
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, n){
            vc[i].clear();
            vc2[i].clear();
            used[i] = 0;
            ans[i] = 0;
        }
        dexout();
        dexout();
        for1(i, 1, n) if(!used[i]) dfs_chim(i);
        dfs_done(ord);
        for1(i, 1, n) cout << ans[i];
        cout << endl;
    }
}