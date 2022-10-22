#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve(){
    ll n,k,a;
    map<int, int> c;
    cin >> n >> k;
    for (ll i = 0; i < n; i++) {
        cin >> a;
        vector<int> l;
        int m = 0;
        while(a){
            c[m++]+=a%k;
            a /= k;
        }
    }
    for (auto [o, v]: c) if (v > 1) {cout << "NO\n"; return ;}
    cout << "YES\n";
}

int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}