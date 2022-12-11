#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int nmax = 80;
const int mmax = (1 << 20);

int dp[nmax][mmax];

const int mod = 1e9 + 7;

void add(int& a, int b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> first(n, n);
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            first[i] = i;
        } else if (i < n - 1) {
            first[i] = first[i + 1];
        }
    }

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < mmax; ++mask) {
            if (!dp[i][mask]) {
                continue;
            }
            int j = first[i];
            if (j == n) {
                continue;
            }
            int val = 1;
            for (int k = j + 1; k <= n && k <= j + 5; ++k) {
                if (val > 20) {
                    continue;
                }
                add(dp[k][mask | (1 << (val - 1))], dp[i][mask]);
                val <<= 1;
                if (k < n) {
                    val += (s[k] - '0');
                }
            }
        }
    }

    //cout << dp[1][1] << '\n';

    int ans = 0;

    for (int i = 0; i <= n; ++i) {
        for (int p = 1; p <= 20; ++p) {
            /*if (dp[i][(1 << p) - 1]) {
                cout << i << " " << p << " " << dp[i][(1 << p) - 1] << "\n";
            }*/
            add(ans, dp[i][(1 << p) - 1]);
        }
    }

    cout << ans << "\n";

}