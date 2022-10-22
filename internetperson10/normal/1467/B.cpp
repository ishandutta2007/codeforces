#include <bits/stdc++.h>

using namespace std;

vector<int> nums;

bool isBad(int a, int b, int c) {
    if(a < b && b > c) return true;
    if(a > b && b < c) return true;
    return false;
}

bool isBad(int x) {
    if(x <= 0 || x >= nums.size()-1) return false;
    return isBad(nums[x-1], nums[x], nums[x+1]);
}

int main() {
    int t;
    int n, k, a, b, c, x, y, z;
    cin >> t;
    while(t--) {
        int ans = 0, b = 9, c = -1, x = -1, a = 9;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x;
            nums.push_back(x);
            ans += isBad(i-1);
        }
        // cout << "ans: " << ans << '\n';
        for(int i = 1; i < nums.size()-1; i++) {
            b = 9;
            x = nums[i];
            c = isBad(i) + isBad(i-1) + isBad(i+1);
            y = nums[i-1], z = nums[i+1];
            if(y > z) swap(y, z);
            nums[i] = y;
            b = min(b, isBad(i) + isBad(i-1) + isBad(i+1));
            nums[i] = z;
            b = min(b, isBad(i) + isBad(i-1) + isBad(i+1));
            nums[i] = x;
            // cout << "changed " << i << " from " << c << " to " << b << '\n';
            a = min(a, b-c);
        }
        cout << min(ans, ans+a) << '\n';
        vector<int>().swap(nums);
    }
}