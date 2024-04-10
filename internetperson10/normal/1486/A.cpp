#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n;
    ll k, ans = 0;
    string s1, s2;
    bool sad = false;
    cin >> t;
    while(t--) {
        cin >> n;
        ans = 0;
        sad = false;
        for(int i = 0; i < n; i++) {
            cin >> k;
            ans += k;
            if(ans < (i*i+i)/2) sad = true;
        }
        cout << (!sad ? "YES" : "NO") << '\n';
    }
}