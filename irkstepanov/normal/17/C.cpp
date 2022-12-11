#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const int mod = 51123987;

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
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<char> types;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            types.pb(s[i]);
        }
    }

    int tt = sz(types);
    vector<int> next_a(tt, -1), next_b(tt, -1), next_c(tt, -1);

    for (int i = tt - 2; i >= 0; --i) {
        if (types[i + 1] == 'a') {
            next_a[i] = i + 1;
        } else {
            next_a[i] = next_a[i + 1];
        }
        if (types[i + 1] == 'b') {
            next_b[i] = i + 1;
        } else {
            next_b[i] = next_b[i + 1];
        }
        if (types[i + 1] == 'c') {
            next_c[i] = i + 1;
        } else {
            next_c[i] = next_c[i + 1];
        }
    }

    int amax = (n + 2) / 3 + 1;

    vector<vector<vector<int> > > dp(amax, vector<vector<int> >(amax, vector<int>(tt)));
    if (types[0] == 'a') {
        dp[1][0][0] = 1;
        if (next_b[0] != -1) {
            dp[0][1][next_b[0]] = 1;
        }
        if (next_c[0] != -1) {
            dp[0][0][next_c[0]] = 1;
        }
    }

    if (types[0] == 'b') {
        dp[0][1][0] = 1;
        if (next_a[0] != -1) {
            dp[1][0][next_a[0]] = 1;
        }
        if (next_c[0] != -1) {
            dp[0][0][next_c[0]] = 1;
        }
    }

    if (types[0] == 'c') {
        dp[0][0][0] = 1;
        if (next_a[0] != -1) {
            dp[1][0][next_a[0]] = 1;
        }
        if (next_b[0] != -1) {
            dp[0][1][next_b[0]] = 1;
        }
    }

    for (int i = 1; i < n; ++i) {
        vector<vector<vector<int> > > dp_new(amax, vector<vector<int> >(amax, vector<int>(tt)));
        for (int a = 0; a < amax; ++a) {
            for (int b = 0; b < amax; ++b) {
                for (int pos = 0; pos < tt; ++pos) {
                    int val = dp[a][b][pos];
                    if (!val) {
                        continue;
                    }
                    if (types[pos] == 'a') {
                        if (a + 1 < amax) add(dp_new[a + 1][b][pos], val);
                        if (next_b[pos] != -1) {
                            if (b + 1 < amax) add(dp_new[a][b + 1][next_b[pos]], val);
                        }
                        if (next_c[pos] != -1) {
                            add(dp_new[a][b][next_c[pos]], val);
                        }
                    }
                    if (types[pos] == 'b') {
                        if (b + 1 < amax) add(dp_new[a][b + 1][pos], val);
                        if (next_a[pos] != -1) {
                            if (a + 1 < amax) add(dp_new[a + 1][b][next_a[pos]], val);
                        }
                        if (next_c[pos] != -1) {
                            add(dp_new[a][b][next_c[pos]], val);
                        }
                    }
                    if (types[pos] == 'c') {
                        add(dp_new[a][b][pos], val);
                        if (next_a[pos] != -1) {
                            if (a + 1 < amax) add(dp_new[a + 1][b][next_a[pos]], val);
                        }
                        if (next_b[pos] != -1) {
                            if (b + 1 < amax) add(dp_new[a][b + 1][next_b[pos]], val);
                        }
                    }
                }
            }
        }
        dp.swap(dp_new);
    }

    int ans = 0;
    if (n % 3 == 0) {
        for (int pos = 0; pos < tt; ++pos) {
            add(ans, dp[n / 3][n / 3][pos]);
        }
    } else if (n % 3 == 1) {
        for (int pos = 0; pos < tt; ++pos) {
            add(ans, dp[n / 3][n / 3][pos]);
            add(ans, dp[n / 3][n / 3 + 1][pos]);
            add(ans, dp[n / 3 + 1][n / 3][pos]);
        }
    } else {
        for (int pos = 0; pos < tt; ++pos) {
            add(ans, dp[n / 3 + 1][n / 3 + 1][pos]);
            add(ans, dp[n / 3 + 1][n / 3][pos]);
            add(ans, dp[n / 3][n / 3 + 1][pos]);
        }
    }

    cout << ans << "\n";

}