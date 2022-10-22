#include <bits/stdc++.h>

using namespace std;

vector<int> nums;

bool bonk(int i) {
    if(i <= 1) return true;
    if(i == nums.size()-1) return true;
    if((nums[i] - nums[i-2] > 1) || (nums[i+1] - nums[i-1] > 1)) return true;
    // cout << i << "unbonkable\n";
    return false;
}

int main() {
    int n, ans = 1, x = 0, y = 0;
    bool sad = false;
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 1; i < n; i++) {
        if(nums[i] <= nums[i-1]) {
            if(!sad) {
                sad = true;
                y = i;
            }
            else {
                x = y;
                y = i;
            }
        }
        if(bonk(y) || y == i) ans = max(ans, i - x + 1);
        else ans = max(ans, i - y + 1);
        if(i == n-1 && y != 0) ans = max(ans, n - y + 1);
    }
    cout << ans << '\n';
}