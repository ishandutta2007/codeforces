#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(m), dist(m);
    for(int i = 0; i < m; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    dist[0] = nums[0] - nums[m-1] + n - 1;
    for(int i = 1; i < m; i++) {
        dist[i] = nums[i] - nums[i-1] - 1;
    }
    sort(dist.rbegin(), dist.rend());
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        ans += max(0, dist[i] - 4 * i - 1);
        if(dist[i] == (4 * i + 1)) ans++;
    }
    cout << n - ans << '\n';
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