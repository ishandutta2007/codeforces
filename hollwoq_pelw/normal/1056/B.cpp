#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS         std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rnd(n)      fixed << setprecision(n)

#define F           first
#define S           second
#define pii         pair<int, int>
#define pll         pair<ll, ll>

#define pb          push_back
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()
#define sz(a)       a.size()

#define pi          acos(-1.0)
#define g_sin(a)    sin(a*pi/180)
#define g_cos(a)    cos(a*pi/180)
#define g_tan(a)    tan(a*pi/180)

#define ms0(a)      memset(a, 0, sizeof(a));

const int mod1 = 998244353, mod2 = 1e+7;

void solve(){
    ll n, m;
    cin >> n >> m;
    ll c[m];
    ms0(c);
    for (ll i = 1; i <= m; i++){
        c[(i*i)%m] += n/m + (i<=n%m&&i>=1);
    }
    
    //for (ll i = 0; i < m; i++) cout << c[i] << ' ';
    
    ll ans = 0;
    for (ll i = 0; i < m; i++){
        ans += c[i]*c[(m-i)%m];
    }
    cout << ans;
}

int main(){
    IOS;
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}