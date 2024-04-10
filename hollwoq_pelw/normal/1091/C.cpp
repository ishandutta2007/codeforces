#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

ll n;
set<ll> a;

void solve(){
    cin >> n;
    for (ll i = 1; i <= sqrt(n); i++){
        if (n%i==0){
            a.insert((n+2-i)*n/i/2);
            a.insert((n+2-n/i)*i/2);
        }
    }
    for (auto p:a) cout << p << ' ';
    
}

int main(){
    IOS;
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}