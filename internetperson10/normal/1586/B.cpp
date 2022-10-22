#include <bits/stdc++.h>
typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> nums;
        nums.push_back(0);
        nums.push_back(n+1);
        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            nums.push_back(b);
        }
        sort(nums.begin(), nums.end());
        int k = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] + 1 < nums[i+1]) {
                k = nums[i] + 1;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(i != k) {
                cout << k << ' ' << i << '\n';
            }
        }
        vector<int>().swap(nums);
    }
}