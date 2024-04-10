#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

multiset<int> s, s2;

ll d() {
    return (*(--s2.end()) - *(s2.begin()));
}

ll f() {
    if(s.size() == 0) return d();
    return (*(--s.end()) - *(s.begin()) + *(--s2.end()) - *(s2.begin()));
}

void solve() {
    int n;
    cin >> n;
    int mi = 1e9, ma = -1;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        s.insert(nums[i]);
    }
    sort(nums.begin(), nums.end());
    cout << nums[n-1] + nums[n-2] - nums[0] - nums[1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}