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

const int mod1 = 998244353, mod2 = 1e+7;

int n, m;
ll ans;
void solve(){
    cin >> n >> m;
    vector<int> a[m];
    ll c[n];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++){
        int x, v;
        cin >> x >> v;
        a[x-1].pb(v);
    }
    for (int i = 0; i < m; i++){
        sort(rall(a[i]));
        ll s = 0;
        for (int j = 0; j < sz(a[i]); j++){
            s += a[i][j];
            if (s > 0) c[j] += s;
        }
    }
    for (int i = 0; i < n; i++){
        ans = max(ans, c[i]);
    }
    cout << ans;
}

int main(){
    IOS;
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}