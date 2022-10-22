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

ll n,s,x;
vector<pll> a;
vector<ll> r;

void solve(){
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> x; 
        s += x;
        a.pb({x, i+1});
    }
    
    sort(all(a));
    
    for (ll i = 0; i < n-1; i++){
        if (a[n-1].F*2 == s-a[i].F){
            r.pb(a[i].S);
        }
    }
    
    if (a[n-2].F*2 == s-a[n-1].F){
        r.pb(a[n-1].S);
    }
    
    cout << sz(r) << endl;
    for (auto m:r) cout << m << ' ';
}

int main(){
    IOS;
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}