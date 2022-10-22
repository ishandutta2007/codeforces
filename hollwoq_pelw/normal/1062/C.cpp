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
#define pdd         pair<ld, ld>

#define eb          emplace_back
#define pb          push_back
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()
#define sz(a)       a.size()
#define sz(a)       a.length()

#define pi          acos(-1.0)
#define g_sin(a)    sin(a*pi/180)
#define g_cos(a)    cos(a*pi/180)
#define g_tan(a)    tan(a*pi/180)

#define ms0(a)      memset(a, 0, sizeof(a));

const int mod1 = 998244353, mod2 = 1e9+7;
const int N = 100005, M = 200010;

ll p(ll a, ll x){
    if (x == 0) return 1;
    if (x == 1) return a;
    ll t = p(a, x/2);
    return ((t*t)%mod2*p(a, x%2))%mod2;
}

ll f(ll x, ll y){
    return ((p(2, y)-1)*p(2, x))%mod2;
}

void solve(){
    int n, q;
    string s;
    cin >> n >> q >> s;
    ll dp[n+1][2];
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++){
        dp[i][0] = dp[i-1][0] + (s[i-1]=='0');
        dp[i][1] = dp[i-1][1] + (s[i-1]=='1');
    }
    ll l, r, x, y;
    while(q--){
        cin >> l >> r;
        ll x = dp[r][0] - dp[l-1][0];
        ll y = dp[r][1] - dp[l-1][1];
        cout << f(x,y) << endl;
    }
} 

int main(){
    IOS;
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}