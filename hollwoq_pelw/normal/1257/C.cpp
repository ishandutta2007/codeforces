#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rnd(n) fixed << setprecision(n)

#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
// #define sz(a) a.size()

const int mod = 998244353, mod2 = 1e+7;

void solve(){
    int n,a,ans=-1;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++){
        cin >> a;
        mp[a].pb(i);
    }
    for (auto [p, v]: mp){
        for (int i = 1; i < v.size(); i++){
            if (ans == -1) ans = v[i]-v[i-1]+1;
            else ans = min(ans, v[i]-v[i-1]+1);
        }
    }
    cout << ans << endl;
}

int main(){
    IOS;
    
    int T; cin >> T;
    while(T--) solve();
    
    return 0;
}