#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> degs(20);
    degs[0] = 1;
    for (int i = 1; i < 20; ++i) {
        degs[i] = degs[i - 1] * 10;
    }

    vector<vector<ll> > dp(n + 1, vector<ll>(n + 1, -1));
    vector<vector<int> > pr(n + 1, vector<int>(n + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i + 1 <= n) {
                ll val = dp[i][j] + (s[i + j] - '0') * degs[n - i - 1];
                if (val > dp[i + 1][j]) {
                    dp[i + 1][j] = val;
                    pr[i + 1][j] = 0;
                }
            }
            if (j + 1 <= n) {
                ll val = dp[i][j] + (s[i + j] - '0') * degs[n - j - 1];
                if (val > dp[i][j + 1]) {
                    dp[i][j + 1] = val;
                    pr[i][j + 1] = 1;
                }
            }
        }
    }

    int i = n, j = n;
    vector<char> ans;
    while (pr[i][j] != -1) {
        //cout << i << " " << j << "\n";
        if (pr[i][j] == 0) {
            ans.pb('H');
            --i;
        } else {
            ans.pb('M');
            --j;
        }
        //cout << i << " " << j << "\n";
    }
    reverse(all(ans));
    for (char c : ans) {
        cout << c;
    }
    cout << "\n";

}