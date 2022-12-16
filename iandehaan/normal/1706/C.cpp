#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

#define MAXN 100'010

ll a[MAXN];
ll dp[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        rep(i, 0, n) cin >> a[i];

        rep(i, 1, n-1) {
            if (n % 2 == 1) {
                // only focus on odd indices
                if (i % 2 == 0) continue;

                ll tobuild = max((ll)0, max(a[i-1]-a[i]+1, a[i+1]-a[i]+1));
                if (i == 1) dp[i] = tobuild;
                else dp[i] = dp[i-2] + tobuild;
            } else {
                // can do odd or even!
                ll tobuild = max((ll)0, max(a[i-1]-a[i]+1, a[i+1]-a[i]+1));
                if (i % 2 == 1) {
                    // can only transition back from odds
                    if (i == 1) dp[i] = tobuild;
                    else dp[i] = dp[i-2] + tobuild;
                } else {
                    // can transition back from previous even, or... from an odd!
                    if (i == 2) dp[i] = tobuild;
                    else {
                        dp[i] = dp[i-2] + tobuild;
                        dp[i] = min(dp[i], dp[i-3] + tobuild);
                    }
                }
            }
        }
        if (n % 2 == 1) cout << dp[n-2] << '\n';
        else cout << min(dp[n-2], dp[n-3]) << '\n';
    }
}