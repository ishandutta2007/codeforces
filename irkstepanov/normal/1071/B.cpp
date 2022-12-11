#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = 1e9;

const int nmax = 2010;

int dp[nmax][nmax];
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = inf;
        }
    }

    dp[0][0] = (a[0][0] == 'a' ? 0 : 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            int val = (a[i][j] == 'a' ? 0 : 1);
            if (i) {
                dp[i][j] = min(dp[i][j], val + dp[i - 1][j]);
            }
            if (j) {
                dp[i][j] = min(dp[i][j], val + dp[i][j - 1]);
            }
        }
    }

    int opt = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] <= k) {
                opt = max(opt, i + j);
            }
        }
    }
    string ans = "";
    for (int i = 0; i <= opt; ++i) {
        ans += "a";
    }

    vector<pii> curr;
    if (opt == -1) {
        curr = {{0, 0}};
        ans += a[0][0];
    } else {
        for (int i = n - 1; i >= 0; --i) {
            int j = opt - i;
            if (j < 0 || j >= n || dp[i][j] > k) {
                continue;
            }
            curr.pb({i, j});
        }
    }

    while (sz(ans) < 2 * n - 1) {
        char c = 'z';
        for (pii p : curr) {
            int i = p.first, j = p.second;
            if (i + 1 < n) {
                c = min(c, a[i + 1][j]);
            }
            if (j + 1 < n) {
                c = min(c, a[i][j + 1]);
            }
        }
        ans += c;
        vector<pii> nx;
        for (pii p : curr) {
            int i = p.first, j = p.second;
            if (i + 1 < n && a[i + 1][j] == c) {
                nx.pb({i + 1, j});
            }
            if (j + 1 < n && a[i][j + 1] == c) {
                nx.pb({i, j + 1});
            }
        }
        //sort(all(nx));
        nx.resize(unique(all(nx)) - nx.begin());
        curr.swap(nx);
    }

    cout << ans << "\n";
 
}