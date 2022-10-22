#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n+1);
        string s;
        cin >> s;
        for(int i = 0; i < n; i++) {
            nums[i+1] = nums[i];
            if(s[i] == 'W') nums[i+1]++;
        }
        int ma = 1e6;
        for(int i = k; i <= n; i++) {
            ma = min(ma, nums[i] - nums[i-k]);
        }
        cout << ma << '\n';
    }
}