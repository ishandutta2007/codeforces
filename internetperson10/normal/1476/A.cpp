#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, w, x, y, z;
    ll a, b, c, d, k, ans=0;
    string s1, s2;
    bool sad = false;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(a < b) {
            if((b%a) == 0) cout << b/a << '\n';
            else cout << b/a+1 << '\n';
        }
        else {
            if((a%b) == 0) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
        
    }
}