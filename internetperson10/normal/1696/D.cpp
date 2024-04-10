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
        vector<vector<int>> stMin(20), stMax(20);
        vector<int> nums(n);
        for(int i = 0; i < 20; i++) {
            stMin[i].resize(n);
            stMax[i].resize(n);
        }
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            stMax[0][i] = stMin[0][i] = nums[i];
        }
        for(int i = 1; i < 20; i++) {
            for(int j = 0; j < n; j++) {
                if(j + (1 << i) <= n) {
                    stMin[i][j] = min(stMin[i-1][j], stMin[i-1][j + (1 << (i-1))]);
                    stMax[i][j] = max(stMax[i-1][j], stMax[i-1][j + (1 << (i-1))]);
                }
            }
        }
        int g = 0;
        int ans = 0;
        while(g != n-1) {
            ans++;
            int l = g+1, r = n;
            int best = nums[g+1];
            while(l != r - 1) {
                int mid = (l + r) / 2;
                int len = mid - g + 1;
                int i = 0;
                while((1 << i) <= len) i++;
                i--;
                int val;
                if(nums[g+1] > nums[g]) val = min(stMin[i][g], stMin[i][mid+1-(1 << i)]);
                else val = max(stMax[i][g], stMax[i][mid+1-(1 << i)]);
                if(val == nums[g]) {
                    l = mid;
                    if(nums[g+1] > nums[g]) best = max(stMax[i][g], stMax[i][mid+1-(1 << i)]);
                    else best = min(stMin[i][g], stMin[i][mid+1-(1 << i)]);
                }
                else r = mid;
            }
            r--; l = g;
            while(l != r - 1) {
                int mid = (l + r + 1) / 2;
                int len = mid - g + 1;
                int i = 0;
                while((1 << i) <= len) i++;
                i--;
                int val;
                if(nums[g+1] > nums[g]) val = max(stMax[i][g], stMax[i][mid+1-(1 << i)]);
                else val = min(stMin[i][g], stMin[i][mid+1-(1 << i)]);
                if(val == best) r = mid;
                else l = mid;
            }
            g = r;
        }
        cout << ans << '\n';
    }
}