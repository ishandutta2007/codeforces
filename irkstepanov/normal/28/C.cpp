#include <bits/stdc++.h>
#include <string.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
vector<int> c;

vector<vector<ll> > choose(55, vector<ll>(55));
vector<ld> degs;

ld solve()
{
    vector<vector<ld> > dp(m, vector<ld>(n + 1));
    for (int j = 0; j <= n && j <= c[0]; ++j) {
        dp[0][j] = choose[n][j] * degs[j];
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= j && k <= c[i]; ++k) {
                dp[i][j] += choose[n - j + k][k] * degs[k] * dp[i - 1][j - k];
            }
        }
    }
    return dp[m - 1][n];
}

int main()
{

    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    choose[0][0] = 1;
    for (int i = 1; i < 55; ++i) {
        choose[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
        }
    }

    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    degs.resize(55);
    degs[0] = 1.0;
    for (int i = 1; i < 55; ++i) {
        degs[i] = degs[i - 1] / m;
    }

    vector<ld> prob(100);
    c.resize(m);

    for (int maxx = 1; maxx < 100; maxx += 1) {
        for (int i = 0; i < m; ++i) {
            c[i] = a[i] * maxx;
        }
        prob[maxx] = solve();
    }

    ld ans = 0;
    for (int maxx = 1; maxx < 100; maxx += 1) {
        ld p = prob[maxx] - prob[maxx - 1];
        ans += p * maxx;
    }

    cout << fixed;
    cout.precision(12);
    cout << ans << "\n";

}