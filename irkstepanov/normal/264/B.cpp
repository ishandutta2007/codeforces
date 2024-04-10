#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int nmax = 100500;

vector<int> primes;
int cnt;

vector<int> f(int a)
{
    vector<int> ans;
    if (a == 1) {
        return ans;
    }
    for (int i = 0; primes[i] * primes[i] <= a; ++i) {
        if (a % primes[i] == 0) {
            ans.pb(i);
            while (a % primes[i] == 0) {
                a /= primes[i];
            }
        }
    }
    if (a != 1) {
        int pos = lower_bound(all(primes), a) - primes.begin();
        ans.pb(pos);
    }
    return ans;
}

int main()
{

    char c[nmax];
    for (int i = 0; i < nmax; ++i) {
        c[i] = true;
    }

    for (int i = 2; i < nmax; ++i) {
        if (c[i]) {
            primes.pb(i);
            for (int j = 2 * i; j < nmax; j += i) {
                c[j] = false;
            }
        }
    }

    cnt = sz(primes);

    vector<int> dp(cnt);
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    int a;
    cin >> a;
    vector<int> v = f(a);

    for (int j : v) {
        dp[j] = 1;
    }

    for (int i = 1; i < n; ++i) {
        cin >> a;
        v = f(a);
        int r = 0;
        for (int j : v) {
            r = max(r, dp[j]);
        }
        for (int j : v) {
            dp[j] = max(dp[j], r + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < cnt; ++i) {
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";

}