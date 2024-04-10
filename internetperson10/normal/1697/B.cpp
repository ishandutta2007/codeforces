#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    nums.push_back(0);
    reverse(nums.begin(), nums.end());
    for(int i = 1; i <= n; i++) {
        nums[i] += nums[i-1];
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << nums[x] - nums[x-y] << '\n';
    }
}