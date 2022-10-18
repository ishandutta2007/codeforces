#include <bits/stdc++.h>
using namespace std;


int MOD = 1'000'000'007;
std::vector<std::vector<long long>> binomial;

void precompute_binomial_coefficients(int ma)
{
    binomial.assign(ma + 1, std::vector<long long>(ma + 1));
    for (int n = 0; n <= ma; n++) {
        binomial[n][0] = 1;
        binomial[n][n] = 1;
        for (int k = 1; k < n; k++) {
            binomial[n][k] =
                (binomial[n - 1][k - 1] + binomial[n - 1][k]) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_binomial_coefficients(1000);
    vector<long long> Bell(1001, 0);
    Bell[0] = 1;
    for (int n = 0; n < 1000; n++) {
        for (int k = 0; k <= n; k++) {
            Bell[n+1] += binomial[n][k] * Bell[k] % MOD;
        }
        Bell[n+1] %= MOD;
    }

    int m, n;
    cin >> m >> n;
    vector<long long> v(m);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            v[j] = 2 * v[j] + (s[j] - '0');
        }
    }

    map<long long, int> ma;
    for (auto x : v)
        ma[x]++;

    long long res = 1;
    for (auto p : ma) {
        res *= Bell[p.second];
        res %= MOD;
    }
    cout << res << '\n';
}