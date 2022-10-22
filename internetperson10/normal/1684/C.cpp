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
        vector<vector<int>> nums(n);
        for(int i = 0; i < n; i++) {
            nums[i].resize(m);
            for(int j = 0; j < m; j++) {
                cin >> nums[i][j];
            }
        }
        vector<vector<int>> sorted = nums;
        set<int> s;
        for(int i = 0; i < n; i++) {
            sort(sorted[i].begin(), sorted[i].end());
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(nums[i][j] != sorted[i][j]) {
                    s.insert(j);
                }
            }
        }
        if(s.size() == 0) {
            cout << "1 1\n";
        }
        else if(s.size() == 2) {
            int x = *(s.begin());
            int y = *(++s.begin());
            bool allSorted = true;
            for(int i = 0; i < n; i++) {
                swap(nums[i][x], nums[i][y]);
                if(nums[i] != sorted[i]) allSorted = false;
            }
            if(!allSorted) cout << "-1\n";
            else cout << x+1 << ' ' << y+1 << '\n';
        }
        else cout << "-1\n";
        s.clear();
    }
}