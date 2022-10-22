/*                 thisiscaau's  code              
        Whats happened happened. Which is an expression of faith 
    in the mechanics of the world. Its not an excuse to do nothing.
*/
/* shortcuts */
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")*/
// for emergency cases
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define left node << 1,tl,tm
#define right node << 1 | 1,tm+1,tr
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
const ll mod = 1e9 + 7, MAXN = 1e5 + 5;
/* declaration */
ll n,m,tc;
ll st[6][MAXN << 2]; // segtree
ll lz[6][MAXN << 2];
ll pre[6][MAXN],coef[10][10];
ll a[MAXN];
/* workspace */

ll binpow(ll a,ll b){
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void build(ll node,ll tl,ll tr,ll pw){
    if (tl == tr){
        st[pw][node] = binpow(tl,pw) * a[tl] % mod;
        return;
    }
    ll tm = (tl+tr) >> 1;
    build(left,pw); build(right,pw);
    st[pw][node] = (st[pw][node << 1] + st[pw][node << 1 | 1]) % mod;
}
void apply (ll node,ll tl,ll tr,ll pw){
    if (lz[pw][node] != -1){
        ll val = lz[pw][node]; ll tm = (tl+tr) >> 1;
        st[pw][node << 1] = ((pre[pw][tm] - pre[pw][tl-1] + mod) % mod) * val % mod;
        st[pw][node << 1 | 1] = ((pre[pw][tr] - pre[pw][tm] + mod) % mod) * val % mod;
        lz[pw][node << 1] = val;
        lz[pw][node << 1 | 1] = val;
        lz[pw][node] = -1;
    }
}

ll query(ll pw,ll l,ll r,ll node = 1,ll tl = 1,ll tr = n){
    if (tl > r || tr < l || l > r) return 0;
    if (l <= tl && tr <= r){
        return st[pw][node];
    }
    apply(node,tl,tr,pw);
    ll tm = (tl + tr) >> 1;
    return ( query(pw,l,r,left) + query(pw,l,r,right) ) % mod;
}
void upd(ll pw,ll l,ll r,ll val,ll node = 1,ll tl = 1,ll tr = n){
    if (l > r || tl > r || tr < l) return;
    if (l <= tl && tr <= r){
        st[pw][node] = val * (pre[pw][tr] - pre[pw][tl-1] + mod) % mod;
        lz[pw][node] = val;
        return;
    }
    apply(node,tl,tr,pw);
    ll tm = (tl + tr) >> 1;
    upd(pw,l,r,val,left); upd(pw,l,r,val,right);
    st[pw][node] = (st[pw][node << 1] + st[pw][node << 1 | 1]) % mod;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    memset(lz,-1,sizeof(lz));
    for (int i = 0 ; i <= 5 ; i++){
        build(1,1,n,i);
    }
    for (int i = 0 ; i <= 5 ; i++){
        for (int j = 1 ; j <= n; j++){
            pre[i][j] = (pre[i][j-1] + binpow(j,i)) % mod;
        }
    }
    for (int i = 0 ; i <= 5 ; i++){
        for (int j = 0 ; j <= i ; j++){
            if (j == 0 || j == i){
                coef[i][j] = 1;
            }
            else {
                coef[i][j] = coef[i-1][j-1] + coef[i-1][j];
            }
        }
    }
    for (int i = 1 ; i <= m ; i++){
        char opt; ll l,r,x;
        cin >> opt >> l >> r >> x;
        if (opt == '='){
            for (int pw = 0 ; pw <= 5 ; pw++){
                upd(pw,l,r,x);
            }
        }
        else {
            // if (l == 1)
            // {
            //     cout << query(x,l,r) << endl;
            // }
            // else 
            {
                ll ans = 0;
                for (int pw = x ; pw >= 0 ; pw--){
                    // cout << ans << " ";
                    ans=(ans+(query(pw,l,r)*binpow(1-l+mod,x-pw)%mod)*coef[x][pw]%mod)%mod;
                    // cout << query(pw, l, r) << " ";
                    // cout << binpow(1 - l, x - pw) << " ";
                    // cout << coef[x][pw] << "\n";
                }
                cout << ans << endl;
            }
        }
    }
}