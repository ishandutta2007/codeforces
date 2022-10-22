#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n, x, y;
    ll k, ans = 0;
    string s1, s2;
    bool sad = false;
    cin >> m >> n;
    nums.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> nums[i];
        ans += nums[i];
    }
    while(n--) {
        cin >> x >> y;
        if(x == 1) {
            ans -= (2*nums[y-1]-1);
            nums[y-1] = 1 - nums[y-1];
        }
        else {
            if(y > ans) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
    }
}