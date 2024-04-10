#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector< vector<int> > a(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '#') a[i][j] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool has_sim = false, has_dif = false;
            for (int k = 0; k < m; ++k) {
                if (a[i][k] == a[j][k] && a[i][k]) {
                    has_sim = true;
                }
                if (a[i][k] != a[j][k]) {
                    has_dif = true;
                }
            }
            if (has_sim && has_dif) {
                cout << "No";
                return 0;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            bool has_sim = false, has_dif = false;
            for (int k = 0; k < n; ++k) {
                if (a[k][i] == a[k][j] && a[k][i]) {
                    has_sim = true;
                }
                if (a[k][i] != a[k][j]) {
                    has_dif = true;
                }
            }
            if (has_sim && has_dif) {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";
}