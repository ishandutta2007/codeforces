#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, w, x, y, z;
    ll a, b, c, d, k, ans=0;
    string s1, s2;
    bool sad = false;
    cin >> t;
    while(t--) {
        x = 0;
        cin >> n >> s1;
        for(int i = 0; i < n-1; i++) {
            if(s1.at(i) == s1.at(i+1)) {
                // cout << "Yay! We go from " << x << " to " << i+1 << '\n';
                for(int j = x; j <= i+1; j++) {
                    if(s1.at(x) == 'L') {
                        if((j-x)%2 == 1) cout << i-x+2 << ' ';
                        else if((j > x && j <= i) || j == 0) cout << 1 << ' ';
                    }
                    else {
                        if((j-x)%2 == 1 && (j == i+1)) break;
                        else if((j-x)%2 == 1) cout << 1 << ' ';
                        else cout << i-x+2 << ' ';
                    }
                }
                x = i+1;
            }
        }
        for(int j = x; j <= n; j++) {
             if(s1.at(x) == 'L') {
                if((j-x)%2 == 1) cout << n-1-x+2 << ' ';
                else if((j > x) || j == 0) cout << 1 << ' ';
            }
            else {
                if((j-x)%2 == 1) cout << 1 << ' ';
                else cout << n-1-x+2 << ' ';
            }
        }
        cout << '\n';
    }
}