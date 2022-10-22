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
        vector<vector<int>> nums(n, vector<int>(m));
        ll ma = -2e9;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> nums[i][j];
                if(ma < nums[i][j]) {
                    ma = nums[i][j];
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(ma == nums[i][j]) {
                    cout << max(n-i, i+1) * max(m-j, j+1) << '\n';
                }
            }
        }
    }
}