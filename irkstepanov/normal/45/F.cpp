#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    if (m == 1) {
        cout << "-1\n";
        return 0;
    }

    const int inf = 1e9;

    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i <= m) {
            cnt[i] = 1;
        } else {
            cnt[i] = 2 + cnt[i - (m - 1)];
        }
    }

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (2 * i <= m) {
            ans[i] = 1;
        } else {
            if (m >= 4) {
                ans[i] = 2 + ans[i - (m / 2) + 1];
            } else {
                ans[i] = inf;
            }

            if (i <= m) {
                int z = m - i;
                if (n - i + z > 0) {
                    ans[i] = min(ans[i], 2 + cnt[i - z + 1]);
                }
            }
        }
    }

    int res = inf;

    for (int t = 0; t < n; ++t) {
        int curr = (t + (m - 2)) / (m - 1);
        curr *= 2;
        if (2 * n - t <= m) {
            res = min(res, curr + 1);
        } else {
            if (n <= m) {
                int z = min(n - t, m - n);
                if (t + z > 0) {
                    res = min(res, curr + 2 + cnt[n - t - z + 1]);
                }
            }
            if (m < t) {
                continue;
            }
            int a = (m - t) / 2;
            if (t + a < 1) {
                continue;
            }
            res = min(res, curr + 2 + ans[n - t - a + 1]);
        }
    }

    cout << (res == inf ? -1 : res) << endl;

}