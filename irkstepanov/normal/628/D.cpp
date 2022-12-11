#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(ll& a, ll b)
{
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

string s;
int m, d;

ll f()
{
    int n = sz(s);
    vector<vector<vector<ll> > > dp(n, vector<vector<ll> >(m, vector<ll>(2)));
    for (int t = 1; t < 10; ++t) {
        if (t == d) {
            continue;
        }
        if (t == s[0] - '0') {
            dp[0][t % m][1] = 1;
        } else if (t < s[0] - '0') {
            ++dp[0][t % m][0];
        }
    }
    for (int i = 1; i < n; ++i) {
        if (i & 1) {
            for (int j = 0; j < m; ++j) {
                add(dp[i][(j * 10 + d) % m][0], dp[i - 1][j][0]);
                if (s[i] - '0' == d) {
                    add(dp[i][(j * 10 + d) % m][1], dp[i - 1][j][1]);
                } else if (s[i] - '0' > d) {
                    add(dp[i][(j * 10 + d) % m][0], dp[i - 1][j][1]);
                }
            }
        } else {
            for (int t = 0; t < 10; ++t) {
                if (t == d) {
                    continue;
                }
                for (int j = 0; j < m; ++j) {
                    add(dp[i][(j * 10 + t) % m][0], dp[i - 1][j][0]);
                    if (t == s[i] - '0') {
                        add(dp[i][(j * 10 + t) % m][1], dp[i - 1][j][1]);
                    } else if (s[i] - '0' > t) {
                        add(dp[i][(j * 10 + t) % m][0], dp[i - 1][j][1]);
                    }
                }
            }
        }
    }
    ll ans = 0;
    add(ans, dp[n - 1][0][0]);
    add(ans, dp[n - 1][0][1]);
    return ans;
}

int main()
{

    //ifstream cin("input.txt");

    cin >> m >> d;
    string a, b;
    cin >> a >> b;

    bool good = true;
    if (a[0] != '1') {
        good = false;
    }
    for (int i = 1; i < sz(a); ++i) {
        if (a[i] != '0') {
            good = false;
            break;
        }
    }

    if (good) {
        s = b;
        cout << f() << "\n";
    } else {
        int j = sz(a) - 1;
        for (; a[j] == '0'; --j) ;
        --a[j];
        for (++j; j < sz(a); ++j) {
            a[j] = '9';
        }
        s = b;
        ll ans = f();
        s = a;
        sub(ans, f());
        cout << ans << "\n";
    }

}