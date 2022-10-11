//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, d[maxn], S, s, f[maxn], ans[maxn];
pair<ll, pll> a[maxn];

ll pw(ll pa, ll pb){
    ll pc = 1;
    while(pb){
        if(pb & 1) pc = pc * pa % mod;
        pa = pa * pa % mod;
        pb >>= 1;
    }
    return pc;
}

int main(){
    fast_io;

    f[0] = 1;
    for(ll i = 1; i < maxn; i++){
        f[i] = f[i - 1] * i % mod;
    }

    cin >> n >> m;
    for(ll i = 0; i < n; i++){
        cin >> d[i];
        S += d[i];
        if(S >= mod) S -= mod;
    }
    sort(d, d + n);
    for(ll i = 0; i < m; i++){
        cin >> a[i].S.F >> a[i].F;
        a[i].S.S = i;
    }
    sort(a, a + m);
    ll p = 0;
    for(ll i = 0; i < m; i++){
        while(p < n && d[p] < a[i].F){
            s += d[p++];
            if(s >= mod) s -= mod;
        }
        ll t = n - p;
        if(t < a[i].S.F) continue;
        ans[a[i].S.S] = (s * (t + 1 - a[i].S.F) % mod * pw(t + 1, mod - 2) % mod + (S - s) * (t - a[i].S.F) % mod * pw(t, mod - 2)) % mod;
    }
    for(ll i = 0; i < m; i++){
        if(ans[i] < 0) ans[i] += mod;
        cout << ans[i] << '\n';
    }

    return 0;
}