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
int sps[100005];
    int ans[100005];
    pair<int, int> dsu[100005];
int f(int x) {
    if(dsu[x].fi == x) return x;
    return dsu[x].fi = f(dsu[x].fi);
}
void solve(int TC) {
    cin >> n;
    int m, k;
    cin >> m >> k;
    int t;
    for(int i = 1; i <= k; i++) {
        cin >> t;
        sps[t] = i;
    }
    vector<pair<int, pair<int, int>>> ed;
    pair<int, pair<int, int>> asd;
    for(int i = 0; i < m; i++) {
        cin >> asd.se.fi >> asd.se.se >> asd.fi;
        ed.pb(asd);
    }
    for(int i = 0; i <= n; i++) {
        dsu[i] = mp(i, 0);
        if(sps[i] > 0) dsu[i].se++;
    }
    sort(ed.begin(), ed.end());
    int anss = 0;
    for(auto x: ed) {
        if(f(x.se.fi) == f(x.se.se)) continue;
        dsu[f(x.se.fi)].se = dsu[f(x.se.se)].se = dsu[f(x.se.fi)].se + dsu[f(x.se.se)].se;
        dsu[f(x.se.se)].fi = dsu[f(x.se.fi)].fi;
        if(dsu[f(x.se.fi)].se == k) {anss = x.fi; break;}
    }
    // for(int i = 1; i <= k; i++) anss = max(anss, ans[i]);
    for(int i = 1; i <= k; i++) cout << anss << ' ';

    // for(int i = 1; i <= n; i++) cin >> arr[i]; // 1 BASED!!
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
}