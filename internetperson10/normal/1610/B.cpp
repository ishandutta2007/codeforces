#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> nums;

bool check(int k) {
    int l = 0, r = nums.size() - 1;
    while(l < r) {
        if(nums[l] == nums[r]) {
            l++; r--;
            continue;
        }
        else if(nums[l] == k) l++;
        else if(nums[r] == k) r--;
        else break;
    }
    if(l < r) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        nums.resize(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        int l = 0;
        while(l < n - 1 - l) {
            if(nums[l] == nums[n-1-l]) l++;
            else break;
        }
        if(check(nums[l]) || check(nums[n-1-l])) {
            cout << "YES\n";
        }
        else cout << "NO\n";
        vector<int>().swap(nums);
    }
}