#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;
mt19937 rnd(58);
const int CS = 1000;
int x[N], y[N];

void solve() {
    int i, j, k, n;
    cin >> n;
    if (n == 2) {
        cout << 1 << endl << 1;
        return;
    }
    int cnt = 0;
    for (i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        if ((x[i] % 2 == 0) ^ (y[i] % 2 == 0))
            ++cnt;
    }
    while (cnt == 0 || cnt == n) {
        if (cnt == n) {
            for (i = 0; i < n; ++i)
                ++x[i];
        } else {
            int cnt1 = 0;
            for (i = 0; i < n; ++i)
            if (x[i] % 2 == 0)
                ++cnt1;
            if (cnt1 == n)
                for (i = 0; i < n; ++i) {
                    x[i] /= 2;
                    y[i] /= 2;
                }
            else if (cnt1 == 0) {
                    for (i = 0; i < n; ++i) {
                        ++x[i];
                        ++y[i];
                    }
                } else {
                    cout << cnt1 << endl;
                    for (i = 0; i < n; ++i)
                    if (x[i] % 2 == 0)
                        cout << i + 1 << ' ';
                    return;


                }
        }
        cnt = 0;
        for (i = 0; i < n; ++i) {
            if ((x[i] % 2 == 0) ^ (y[i] % 2 == 0))
                ++cnt;
        }
    }
    vector <int> ans;
    for (i = 0; i < n; ++i) {
        if (x[i] % 2 == 0 ^ y[i] % 2 == 0)
            ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}