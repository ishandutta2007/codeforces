#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums.rbegin(), nums.rend());
        cout << nums[0]+nums[1] << '\n';
    }
}