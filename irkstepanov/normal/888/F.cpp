#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int> > dp(n, vector<int>(n));
    vector<vector<int> > dp1(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;

            dp1[i][j] += dp[i + 1][j];
            for (int k = i + 1; k < j; ++k) {
                if (a[i][k]) {
                    int val = dp1[i][k];
                    mul(val, dp1[k][j]);
                    add(dp1[i][j], val);
                }                
            }

            for (int k = i + 1; k <= j; ++k) {
                if (a[i][k]) {
                    int val = dp1[i][k];
                    mul(val, dp[k][j]);
                    add(dp[i][j], val);
                }
            }
        }
    }

    cout << dp[0][n - 1] << "\n";

}