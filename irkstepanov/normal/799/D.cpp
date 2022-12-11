#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<int> x;
int n;
const int nmax = 100500;
const int inf = 1e9;

int solve(int a, int b, int h, int w)
{
    set<int> sa, sb;
    vector<int> classa, classb;
    int ida[nmax], idb[nmax];
    for (int i = 1; i < nmax; ++i) {
        ida[i] = idb[i] = -1;
        if (!(sa.count((a + i - 1) / i))) {
            sa.insert((a + i - 1) / i);
            classa.pb((a + i - 1) / i);
        }

        if (!(sb.count((b + i - 1) / i))) {
            sb.insert((b + i - 1) / i);
            classb.pb((b + i - 1) / i);
        }
    }

    for (int i = 0; i < sz(classa); ++i) {
        ida[classa[i]] = i;
    }
    for (int i = 0; i < sz(classb); ++i) {
        idb[classb[i]] = i;
    }

    vector<vector<int> > dp(sz(classa), vector<int>(sz(classb), inf));
    dp[0][0] = 0;
    for (int z = 0; z < n; ++z) {
        vector<vector<int> > dpNext = dp;
        for (int i = 0; i < sz(classa); ++i) {
            for (int j = 0; j < sz(classb); ++j) {
                int p = ida[(classa[i] + x[z] - 1) / x[z]];
                dpNext[p][j] = min(dpNext[p][j], dp[i][j] + 1);
                p = idb[(classb[j] + x[z] - 1) / x[z]];
                dpNext[i][p] = min(dpNext[i][p], dp[i][j] + 1);
            }
        }
        dp.swap(dpNext);
    }
    int ans = inf;
    for (int i = 0; i < sz(classa); ++i) {
        for (int j = 0; j < sz(classb); ++j) {
            if (h >= classa[i] && w >= classb[j]) {
                ans = min(ans, dp[i][j]);
            }
        }
    }
    return ans;
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, h, w;
    cin >> a >> b >> h >> w >> n;

    x.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    sort(all(x));
    reverse(all(x));
    while (sz(x) > 60) {
        x.pop_back();
    }
    n = sz(x);

    int ans = min(solve(a, b, h, w), solve(a, b, w, h));
    if (ans == inf) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }

}