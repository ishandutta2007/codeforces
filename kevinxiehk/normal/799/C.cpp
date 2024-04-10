#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
using namespace std;
const int maxn = 1000005; // REMEMBER TO CHANGE UPPER BOUND
int mod = 1000000007, mod2 = 998244353, n, fac[maxn + 5], invfac[maxn + 5], arr[maxn + 5];
void mod998() {swap(mod, mod2);}
bool isprime(int k) {
    for(int i = 2; i * i <= k; i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2); 
    return (b % 2 == 1 ? t * t % mod * a % mod : t * t % mod);
}
int inv(int a) {return bm(a, mod - 2);}
int ncr(int n, int r) {
    return (r > n ? 0LL : fac[n] * invfac[r] % mod * invfac[n - r] % mod);
}
void pre_fac(int n) {
    fac[0] = 1; for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
}
void pre_invfac(int n) {
    for(int i = 0; i <= n; i++) invfac[i] = inv(fac[i]);
}
void solve(int TC) {
    cin >> n;
    int c, d;
    cin >> c >> d;
    vector<pair<int, int>> cc, dd; // cost, beauty
    pair<int, int> t;
    char tt;
    cc.pb(mp(1000000, -inf));
    cc.pb(mp(0, -inf));
    dd.pb(mp(0, -inf));
    dd.pb(mp(1000000, -inf));
    for(int i = 0; i < n; i++) {
        cin >> t.se >> t.fi >> tt;
        if(tt == 'C') cc.pb(t);
        else dd.pb(t);
    }
    sort(cc.rbegin(), cc.rend());
    sort(dd.rbegin(), dd.rend());
    int ccnt = cc.size();
    int dcnt = dd.size();
    int mxc = -inf, mxd = -inf;
    for(auto x: cc) if(x.fi <= c) mxc = max(mxc, x.se);
    for(auto x: dd) if(x.fi <= d) mxd = max(mxd, x.se);
    int ans = mxc + mxd;
    vector<pair<int, int>> ccc = cc, ddd = dd; // cost, beauty
    for(int i = ccnt - 2; i >= 0; i--) {
        cc[i].se = max(cc[i].se, cc[i + 1].se);
    }
    for(int i = dcnt - 2; i >= 0; i--) {
        dd[i].se = max(dd[i].se, dd[i + 1].se);
    }
    for(int i = 0; i < ccnt - 1; i++) {
        if(cc[i].fi > c) continue;
        int lef = c - cc[i].fi;
        int l = i + 1, r = ccnt - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(cc[m].fi <= lef) r = m;
            else l = m + 1;
        }
        // cout << i << ' ' << l << '\n';
        ans = max(ans, ccc[i].se + cc[l].se);
    }
    for(int i = 0; i < dcnt - 1; i++) {
        if(dd[i].fi > d) continue;
        int lef = d - dd[i].fi;
        int l = i + 1, r = dcnt - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(dd[m].fi <= lef) r = m;
            else l = m + 1;
        }
        ans = max(ans, ddd[i].se + dd[l].se);
    }
    ans = max(0LL, ans);
    cout << ans << '\n';
    // for(int i = 1; i <= n; i++) cin >> arr[i]; // 1 BASED!!
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
}