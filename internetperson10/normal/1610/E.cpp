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
        vector<int> nums(n);
        vector<int> extr(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        extr[n-1] = 1;
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] == nums[i+1]) {
                extr[i] = extr[i+1] + 1;
            }
            else {
                extr[i] = 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < n-1; i++) {
            int g = i+1;
            int curr = 2;
            if(nums[i] == nums[i+1]) {
                curr += (extr[g] - 1);
                g += (extr[g] - 1);
            }
            while(g < n-1) {
                if(nums[n-1] < 2*nums[g] - nums[i]) break;
                int l = g, r = n-1;
                while(l != r - 1) {
                    int mid = (l+r)/2;
                    if(nums[mid] >= 2*nums[g] - nums[i]) r = mid;
                    else l = mid;
                }
                g = r;
                curr++;
            }
            ans = max(ans, curr);
        }
        cout << n-ans << '\n';
        vector<int>().swap(nums);
        vector<int>().swap(extr);
    }
}