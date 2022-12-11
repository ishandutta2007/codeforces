#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

const int inf = 1e9;

vector<int> primes;
int pp;

void init()
{
    int s = 60;
    vector<char> p(s, true);
    for (int i = 2; i < s; ++i) {
        if (!p[i]) {
            continue;
        }
        primes.pb(i);
        for (int j = 2 * i; j < s; j += i) {
            p[j] = false;
        }
    }
    pp = sz(primes);
}

bool bit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

int main()
{

    init();

    int n;
    cin >> n;

    vector<vector<int> > dp(n + 1, vector<int>(1 << pp, inf));
    vector<vector<int> > p(n + 1, vector<int>(1 << pp));
    dp[0][0] = 0;
    p[0][0] = -1;

    vector<int> divs(61);
    for (int x = 1; x <= 61; ++x) {
        for (int b = 0; b < pp; ++b) {
            if (x % primes[b] == 0) {
                divs[x] |= (1 << b);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int mask = 0; mask < (1 << pp); ++mask) {
            for (int val = 1; val <= 60; ++val) {
                if (divs[val] & mask) {
                    continue;
                }
                int new_mask = (mask | divs[val]);
                if (dp[i][mask] + abs(a - val) < dp[i + 1][new_mask]) {
                    dp[i + 1][new_mask] = dp[i][mask] + abs(a - val);
                    p[i + 1][new_mask] = val;
                }
            }
        }
    }

    int ans = inf, curr;
    for (int mask = 0; mask < (1 << pp); ++mask) {
        if (ans > dp[n][mask]) {
            ans = dp[n][mask];
            curr = mask;
        }
    }
    vector<int> v;
    for (int i = n; i >= 1; --i) {
        int x = p[i][curr];
        v.pb(x);
        curr ^= divs[x];
    }
    reverse(all(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";

}