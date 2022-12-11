#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

const int inf = 100500;

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int> > dp(n, vector<int>(3, inf));
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (i == 0) {
            dp[i][0] = 1;
            if (a & 1) {
                dp[i][1] = 0;
            }
            if (a & 2) {
                dp[i][2] = 0;
            }
        } else {
            dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
            if (a & 1) {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
            }
            if (a & 2) {
                dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
            }
        }
    }

    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << "\n";

}