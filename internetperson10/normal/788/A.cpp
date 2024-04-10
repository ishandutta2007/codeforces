#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<ll> nums;

int main() {
    int n;
    cin >> n;
    nums.resize(n);
    ll mi = 0, ma = 0;
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 0; i < n-1; i++) {
        nums[i] = abs(nums[i+1] - nums[i]);
    }
    nums.pop_back();
    for(int i = 1; i < n-1; i++) {
        if(i%2) nums[i] = nums[i-1] - nums[i];
        else nums[i] = nums[i-1] + nums[i];
    }
    for(int i = 0; i < n-1; i++) {
        mi = min(mi, nums[i]);
        ma = max(ma, nums[i]);
    }
    cout << ma-mi << '\n';
}