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
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 500005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

ii pr[maxN];

int tree[maxN];

void update(int plc, int val){
    while(plc <= n){
        tree[plc] += val;
        plc += (plc & -plc);
    }
}

int take(int plc){
    int res = 0;
    while(plc){
        res += tree[plc];
        plc -= (plc & -plc);
    }
    return res;
}

int ans = 0;
void solve(){
    for1(i, 1, n){
        pr[i].fi = a[i];
        pr[i].se = i;
    }
    sort(pr + 1, pr + n + 1);
    memset(tree, 0, sizeof(tree));
    for1(i, 1, n){
        int val = pr[i].fi; // val
        int id = pr[i].se; // id
        val *= (take(id) * (n + 1 - id)) % mod;
        ans += val;
        ans %= mod;
        update(id, id);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> a[i];
        ans += a[i] * ((i * (n + 1 - i)) % mod);
        ans %= mod;
    }
    solve();
    reverse(a + 1, a + n + 1);
    solve();
    cout << (ans % mod + mod) % mod << endl;
}