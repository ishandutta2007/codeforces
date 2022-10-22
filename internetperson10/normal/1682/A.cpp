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
        string s;
        cin >> s;
        int ans = 0;
        vector<int> nums(n);
        for(int i = 1; i < n; i++) {
            nums[i] = nums[i-1];
            if(s[i] != s[i-1]) nums[i]++;
        }
        int x;
        if(n%2) x = nums[n/2];
        else if(s[n/2] = s[(n-1)/2]) x = nums[n/2];
        else x = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == x) ans++;
        }
        cout << ans << '\n';
    }
}