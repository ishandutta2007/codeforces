#include <bits/stdc++.h>

using namespace std;

vector<int> nums;

int main() {
    int n, k;
    cin >> n >> k;
    nums.resize(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] >= nums[k-1] && nums[i] > 0) ans++;
    }
    cout << ans << '\n';
}