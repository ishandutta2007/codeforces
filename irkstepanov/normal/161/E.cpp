#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

const int nmax = 100000;
int mind[nmax];
vector<int> primes;
vector<int> lst[6][6][10000];

int get(int val, int n, int p) {
    for (int i = 0; i < n - p; ++i) {
        val /= 10;
    }
    return val;
}

int dp[1000][1000];

vector<int> curr;
int ans;

void rec(int r, int n) {
    if (r == n - 1) {
        ans += sz(lst[n][n - 1][curr.back()]);
        return;
    }
    if (n == 5 && r == 3) {
        ans += dp[curr[3]][curr[4]];
        return;
    }
    for (int old : lst[n][r][curr[r]]) {
        vector<int> digits;
        int p = old;
        for (int j = 0; j < n; ++j) {
            digits.pb(p % 10);
            p /= 10;
        }
        reverse(all(digits));
        for (int i = r + 1; i < n; ++i) {
            curr[i] *= 10;
            curr[i] += digits[i];
        }
        rec(r + 1, n);
        for (int i = r + 1; i < n; ++i) {
            curr[i] /= 10;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    for (int i = 2; i < nmax; ++i) {
        mind[i] = i;
    }
    for (int i = 2; i < nmax; ++i) {
        if (mind[i] == i) {
            primes.pb(i);
        }
        for (int p : primes) {
            if (p > mind[i] || p * i >= nmax) {
                break;
            }
            mind[p * i] = p;
        }
    }

    for (int n = 1; n <= 5; ++n) {
        int lim = 1; /// 10^p
        for (int p = 0; p < n; ++p) {
            int ptr = 0;
            for (int val = 0; val < lim; ++val) {
                while (ptr < sz(primes) && get(primes[ptr], n, p) == val) {
                    lst[n][p][val].pb(primes[ptr++]);
                }
            }
            lim *= 10;
        }
    }

    for (int x = 0; x < 1000; ++x) {
        for (int y = 0; y < 1000; ++y) {
            for (int p : lst[5][3][x]) {
                int d = p % 10;
                int newy = 10 * y + d;
                dp[x][y] += sz(lst[5][4][newy]);
            }
        }
    }

    int tt;
    cin >> tt;

    while (tt--) {
        int p;
        cin >> p;
        int old = p;
        curr.clear();
        vector<int> digits;
        while (p) {
            digits.pb(p % 10);
            p /= 10;
        }
        int n = sz(digits);
        reverse(all(digits));
        curr.pb(old);
        for (int i = 1; i < n; ++i) {
            curr.pb(digits[i]);
        }
        ans = 0;
        rec(1, n);
        cout << ans << "\n";
    }

}