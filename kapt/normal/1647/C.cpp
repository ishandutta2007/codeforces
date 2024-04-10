#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;
string arr[MAXN];

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        if (arr[0][0] == '1') {
            cout << -1 << endl;
            continue;
        }
        vector<array<int, 4>> ans;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j > 0; --j) {
                if (arr[i][j] == '1') {
                    ans.push_back({i, j - 1, i, j});
                }
            }
            if (arr[i][0] == '1' && i) {
                ans.push_back({i - 1, 0, i, 0});
            }
        }
        cout << ans.size() << endl;
        for (auto elem : ans) {
            cout << elem[0] + 1 << " " << elem[1] + 1 << " " << elem[2] + 1 << " " << elem[3] + 1 << endl;
        }
    }
    return 0;
}