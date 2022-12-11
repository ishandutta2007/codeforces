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

const int nmax = 55;
const int kmax = 2100;

int dp[nmax][kmax];

const int inf = 1e9;

void upd(int i, int j, int val) {
    if (dp[i][j] == -1) {
        dp[i][j] = val;
    } else {
        dp[i][j] = min(dp[i][j], val);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s, k;
    cin >> n >> s >> k;
    --s;

    memset(dp, -1, sizeof(dp));

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<char> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    int ans = inf;

    for (int i = 0; i < n; ++i) {
        if (a[i] >= k) {
            ans = min(ans, abs(i - s));
        } else {
            dp[i][a[i]] = abs(i - s);
        }
    }

    for (int cnt = 1; cnt < k; ++cnt) {
        for (int i = 0; i < n; ++i) {
            if (dp[i][cnt] == -1) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (a[j] <= a[i] || c[j] == c[i]) {
                    continue;
                }
                if (cnt + a[j] >= k) {
                    ans = min(ans, dp[i][cnt] + abs(i - j));
                } else {
                    upd(j, cnt + a[j], dp[i][cnt] + abs(i - j));
                }
            }
        }
    }

    cout << (ans == inf ? -1 : ans) << "\n";
    
}