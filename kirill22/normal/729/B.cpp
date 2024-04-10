#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool f = false;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && f) ans++;
            f |= a[i][j];
        }
        f = false;
        for (int j = m - 1; j >= 0; j--) {
            if (a[i][j] == 0 && f) ans++;
            f |= a[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        bool f = false;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 0 && f) ans++;
            f |= a[i][j];
        }
        f = false;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i][j] == 0 && f) ans++;
            f |= a[i][j];
        }
    }
    cout << ans;
}