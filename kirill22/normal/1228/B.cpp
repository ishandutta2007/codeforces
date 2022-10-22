#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n][m];
    vector<int> b(n), c(m);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i]; j++) {
            a[i][j] = 1;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < c[j]; i++) {
            a[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        int j = 0;
        while (j < m && a[i][j] == 1) {
            j++;
            tmp++;
        }
        if (tmp > b[i]) {
                cout << 0;
                return 0;
        }
    }
    for (int j = 0; j < m; j++) {
        int tmp = 0;
        int i = 0;
        while (i < n && a[i][j] == 1) {
            i++;
            tmp++;
        }
        if (tmp > c[j]) {
                cout << 0;
                return 0;
        }
    }
    int ans = 1;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                //cout << a[i][j] << " " << b[i] << " " << c[j] << endl;
                if (b[i] < j && c[j] < i) {
                    ans = (ans * 2) % mod;
                }
            }
        }
    }
    cout << ans;
}