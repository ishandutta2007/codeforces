#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int ans[(1 << 22)];

vector<int> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < (1 << 22); i++) {
        ans[i] = -1;
    }
    int n;
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        ans[nums[i]] = nums[i];
    }
    for(int i = 0; i < 22; i++) {
        for(int j = 0; j < (1 << 22); j++) {
            if(j & (1 << i)) {
                ans[j] = max(ans[j], ans[j ^ (1 << i)]);
            }
        }
    }
    int g = (1 << 22) - 1;
    for(int i = 0; i < n; i++) {
        cout << ans[g ^ nums[i]] << ' ';
    }
}