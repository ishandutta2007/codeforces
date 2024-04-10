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

int n,a,s;
void solve(){
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a;
        mp[a].pb(i);
    }
    for (auto [s,v]:mp){
        if (v.size()>=3 || (v.size()==2 && v[0] != v[1]-1)){
            cout << "YES\n";
            return ;
        }
    }
    cout << "NO\n";
}

int main(){
    IOS;
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}