#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 100500;

void add(int& a, int b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b)
{
    ll c = ll(a) * ll(b);
    a = c % mod;
}

void sub(int& a, int b)
{
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

int binpow(int a, int n)
{
    int ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        n >>= 1;
        mul(a, a);
    }
    return ans;
}

vector<int> fact(nmax), rfact(nmax);

void init()
{
    fact[0] = rfact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = binpow(fact[i], mod - 2);
    }
}

int choose(int n, int k)
{
    if (n < k) {
        return 0;
    }
    int ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int main()
{

    //ifstream cin("input.txt");

    init();

    int n, m, a, b, k;
    cin >> n >> m >> a >> b >> k;

    int prob = a;
    mul(prob, binpow(b, mod - 2));

    int x = 1, y = 1;
    sub(y, prob);
    int rev_y = binpow(y, mod - 2);
    y = binpow(y, k);
    int deg = k;
    vector<int> pr(m + 1);
    pr[0] = y;
    for (int i = 1; i <= m; ++i) {
        mul(x, prob);
        mul(y, rev_y);
        --deg;
        if (deg == 0) {
            y = 1;
        }
        pr[i] = choose(k, i);
        mul(pr[i], x);
        mul(pr[i], y);
    }

    vector<vector<int> > p(m, vector<int>(m + 1));
    for (int l = 0; l < m; ++l) {
        for (int r = l + 1; r <= m; ++r) {
            p[l][r] = pr[l];
            mul(p[l][r], pr[m - r]);
        }
    }

    vector<int> sum_p(m + 1);
    for (int r = 0; r <= m; ++r) {
        for (int l = 0; l < r; ++l) {
            add(sum_p[r], p[l][r]);
        }
    }

    vector<vector<int> > dp(n + 1, vector<int>(m + 1));
    vector<vector<int> > sum_dp(n + 1, vector<int>(m + 1));
    dp[0][m] = sum_dp[0][m] = 1;

    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int r = 0; r <= m; ++r) {
            int val = sum_dp[i - 1][m];
            sub(val, sum_dp[i - 1][m - r]);
            mul(val, sum_p[r]);
            dp[i][r] = val;
            if (r) {
                val = pr[r - 1];
                mul(val, sum_dp[i - 1][r - 1]);
                add(sum, val);
            }
            val = sum;
            mul(val, pr[m - r]);
            sub(dp[i][r], val);
            if (r) {
                sum_dp[i][r] = sum_dp[i][r - 1];
            }
            add(sum_dp[i][r], dp[i][r]);
        }
    }

    cout << sum_dp[n][m] << "\n";

}