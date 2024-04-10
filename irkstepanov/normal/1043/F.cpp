#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 300500;

int cnt[nmax]; // cnt[x] == number of values divisible by x
bool a[nmax];
int mind[nmax];
int moebius[nmax];
ll total[nmax];
int dp[nmax];

int trans(int val) {
    if (val == 1) {
        return 1;
    }
    if (mind[val] == val) {
        return val;
    }
    int p = mind[val];
    while (mind[val] == p) {
        val /= p;
    }
    return trans(val) * p;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < nmax; ++i) {
        mind[i] = i;
    }
    vector<int> primes;
    for (int i = 2; i < nmax; ++i) {
        if (mind[i] == i) {
            primes.pb(i);
        }
        for (int p : primes) {
            if (p * i >= nmax || p > mind[i]) {
                break;
            }
            mind[p * i] = p;
        }
    }

    int n;
    cin >> n;
    bool one = false;
    int g = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x = trans(x);
        g = __gcd(g, x);
        a[x] = true;
        if (x == 1) {
            one = true;
        }
    }

    if (g != 1) {
        cout << "-1\n";
        return 0;
    }
    if (one) {
        cout << "1\n";
        return 0;
    }

    for (int i = 1; i < nmax; ++i) {
        for (int j = i; j < nmax; j += i) {
            if (a[j]) {
                ++cnt[i];
            }
        }
    }

    moebius[1] = 1;
    for (int i = 2; i < nmax; ++i) {
        if (i == mind[i]) {
            moebius[i] = -1;
            continue;
        }
        int p = mind[i];
        if (p == mind[i / p]) {
            moebius[i] = 0;
        } else {
            moebius[i] = -moebius[i / p];
        }
    }

    for (int i = 1; i < nmax; ++i) {
        if (moebius[i] == 0) {
            continue;
        }
        for (int j = i; j < nmax; j += i) {
            total[j] += cnt[i] * moebius[i];
        }
    }

    dp[1] = 0;
    const int inf = 1e9;
    for (int u = 2; u < nmax; ++u) {
        dp[u] = inf;
    }

    for (int v = 1; v < nmax; ++v) {
        if (moebius[v] == 0) {
            continue;
        }
        for (int u = 2 * v, j = 2; u < nmax; u += v, ++j) {
            if (moebius[u] == 0) {
                continue;
            }
            if (total[j]) {
                /*if (u == 6) {
                    cout << "!" << v << " " << j << " " << dp[v] << endl;
                }*/
                dp[u] = min(dp[u], 1 + dp[v]);
            }
        }
    }

    int ans = inf;
    for (int i = 1; i < nmax; ++i) {
        if (a[i]) {
            ans = min(ans, dp[i] + 1);
        }
    }
    cout << ans << "\n";

}