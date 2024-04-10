#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<vector<int>> ans;

bool check(int i, int j) {
    if (i < 0 || i >= h || j < 0 || j >= w) {
        return false;
    }
    return ans[i][j];
}

bool is_p(int i, int j) {
    bool res = true;
    for (int x = i - 1; x <= i + 1; ++x) {
        for (int y = j - 1; y <= j + 1; ++y) {
            res &= (!check(x, y));
        }
    }
    return res;
}

main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> h >> w;
        ans.clear();
        ans.resize(h, vector<int> (w, 0));
        for (int i = 0; i < w; ++i) {
            if (is_p(0, i)) {
                ans[0][i] = 1;
            }
        }
        for (int j = 0; j < h; ++j) {
            if (is_p(j, w - 1)) {
                ans[j][w - 1] = 1;
            }
        }
        for (int i = w - 1; i >= 0; --i) {
            if (is_p(h - 1, i)) {
                ans[h - 1][i] = 1;
            }
        }
        for (int j = h - 1; j >= 0; --j) {
            if (is_p(j, 0)) {
                ans[j][0] = 1;
            }
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << ans[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}