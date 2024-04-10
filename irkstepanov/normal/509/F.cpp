#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mult(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

int main()
{

    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<vector<ll> > dp1(n, vector<ll>(n));
    vector<vector<ll> > dp2(n, vector<ll>(n));

    for (int i = 0; i < n; ++i) {
        dp1[i][i] = 1;
        dp2[i][i] = 1;
    }

    for (int i = 0; i < n - 1; ++i) {
        dp1[i][i + 1] = 1;
        if (p[i] < p[i + 1]) {
            dp2[i][i + 1] = 2;
        } else {
            dp2[i][i + 1] = 1;
        }
    }

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            dp1[i][j] = dp1[i + 1][j];
            for (int c = i + 2; c <= j; ++c) {
                if (p[c] > p[i + 1]) {
                    ll t = dp1[i + 1][c - 1];
                    mult(t, dp2[c][j]);
                    add(dp1[i][j], t);
                }
            }
            dp2[i][j] = dp1[i][j];
            for (int c = i + 1; c <= j; ++c) {
                if (p[c] > p[i]) {
                    ll t = dp1[i][c - 1];
                    mult(t, dp2[c][j]);
                    add(dp2[i][j], t);
                }
            }
        }
    }

    cout << dp1[0][n - 1] << "\n";

}