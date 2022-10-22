#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int leastOps(vector<ll> &v) { // This is O(n), only considers d = 0 case
    unordered_map<ll, int> m;
    int ans = 0;
    for(ll g : v) {
        ans = max(ans, ++m[g]);
    }
    return v.size() - ans;
}

int SQRTN = 111;
int SQRTB = 901;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> nums(n), nums2(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ans = n-1, ans2 = 0;
    unordered_map<int, int> m;
    for(int i = -SQRTN; i <= SQRTN; i++) {
        for(int j = 0; j < n; j++) {
            ans2 = max(ans2, ++m[nums[j] + (i * j)]);
        }
        m.clear();
    }
    ans = n - ans2;
    unordered_map<ll, int> m2;
    cerr << "YES" << endl;
    ans2 = 0;
    for(int i = 0; i < n; i++) {
        int x = min(n, i + SQRTB);
        for(int j = i+1; j < x; j++) {
            if((nums[i] - nums[j]) % (abs(i - j))) continue;
            ll x = (nums[i] - nums[j]) / (i - j);
            ll p = (1e6 + 69) * (nums[i] - (i * x)) + x;
            ans2 = max(ans2, ++m2[p]);
        }
    }
    for(ll i = 0; i < n; i++) {
        if(i * i + i == ans2 * 2) ans = min(ans, n - 1 - (int)i);
    }
    cout << ans << '\n';
}