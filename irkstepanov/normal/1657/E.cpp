#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;


void add(int& a, int b, int p) {
    a += b;
    if (a >= p) {
        a -= p;
    }
}

void sub(int& a, int b, int p) {
    a -= b;
    if (a < 0) {
        a += p;
    }
}

void mul(int& a, int b, int p) {
    ll c = ll(a) * b;
    if (c >= p) {
        c %= p;
    }
    a = c;
}

int binpow(int a, int n, int p) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a, p);
        }
        mul(a, a, p);
        n >>= 1;
    }
    return ans;
}

const int mod = 998244353;
const int nmax = 300;
int bin[nmax][nmax];
int dp[nmax][nmax];
int bin_norm[nmax][nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    bin[0][0] = 1;
    for (int i = 1; i < nmax; ++i) {
        bin[i][0] = 1;
        for (int j = 1; j < nmax; ++j) {
            bin[i][j] = bin[i - 1][j];
            add(bin[i][j], bin[i - 1][j - 1], mod - 1);
        }
    }

    bin_norm[0][0] = 1;
    for (int i = 1; i < nmax; ++i) {
        bin_norm[i][0] = 1;
        for (int j = 1; j < nmax; ++j) {
            bin_norm[i][j] = bin_norm[i - 1][j];
            add(bin_norm[i][j], bin_norm[i - 1][j - 1], mod);
        }
    }

    int n, k;
    cin >> n >> k;

    for (int w = 0; w <= k; ++w) {
        dp[0][w] = 1;
    }

    for (int m = 1; m <= n - 1; ++m) {
        for (int w = 1; w <= k; ++w) {
            dp[m][w] = dp[m][w - 1];
            for (int a = 1; a <= m; ++a) {
                int cnt = bin[m][2];
                sub(cnt, bin[m - a][2], mod - 1);
                int val = binpow(k - w + 1, cnt, mod);
                mul(val, dp[m - a][w - 1], mod);
                mul(val, bin_norm[m][a], mod);
                add(dp[m][w], val, mod);
                /*if (m == 2 && w == 2) {
                    cout << "!!" << a << " " << val << endl;
                }*/
            }
            //cout << "!" << m << " " << w << " " << dp[m][w] << endl;
        }
    }

    cout << dp[n - 1][k] << "\n";

}