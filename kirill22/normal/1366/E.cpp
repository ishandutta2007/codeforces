#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ans = 1;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    if (m > n) {
        cout << 0;
        return 0;
    }
    map<int, int> lst;
    for (int i = 0; i < n; i++) lst[a[i]] = i;
    vector<int> r(m);
    for (int i = 0; i < m; i++) {
        if (lst.find(b[i]) == lst.end()) {
            cout << 0;
            return 0;
        }
        r[i] = lst[b[i]];
    }
    for (int i = 1; i < m; i++) {
        if (r[i] < r[i - 1]) {
            cout << 0;
            return 0;
        }
    }
    vector<int> L(m, -1), R(m, -1);
    for (int i = 0; i < m; i++) {
        int _l = 0, _r = n - 1;
        if (i) _l = r[i - 1] + 1;
        if (i < m - 1) _r = r[i + 1] - 1;
        int tl = r[i], tr = r[i];
        while (tl - 1 >= _l) {
            if (a[tl - 1] < a[r[i]]) {
                break;
            }
            tl--;
        }
        while (tr + 1 <= _r) {
            if (a[tr + 1] < a[r[i]]) {
                break;
            }
            tr++;
        }
        L[i] = tl, R[i] = tr;
    }
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            if (L[i] != 0) {
                cout << 0;
                return 0;
            }
        }
        if (i == m - 1) {
            if (R[i] != n - 1) {
                cout << 0;
                return 0;
            }
        }
        if (!i) continue;
        int x = max(0ll, R[i - 1] - L[i] + 2);
        ans = (ans * x) % mod;
    }
    cout << ans;
}