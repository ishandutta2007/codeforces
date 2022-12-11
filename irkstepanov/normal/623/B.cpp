#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

const ll inf = 1e18;

int n;
ll a, b;
vector<int> v;

vector<int> factorization(int x)
{
    vector<int> ans;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            ans.pb(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x != 1) {
        ans.pb(x);
    }
    return ans;
}

ll f(const vector<int>& m)
{
    if (n == 1) {
        return 0;
    }
    vector<ll> dp1(n), dp2(n), dp3(n);
    dp1[0] = 0;
    dp2[0] = inf;
    dp3[0] = inf;
    for (int i = 1; i < n; ++i) {
        if (m[i] == 0) {
            dp1[i] = dp1[i - 1];
            dp2[i] = min(a + dp1[i - 1], dp2[i - 1] + a);
            dp3[i] = min(dp2[i - 1], dp3[i - 1]);
        } else if (m[i] == 1) {
            dp1[i] = dp1[i - 1] + b;
            dp2[i] = min(a + dp1[i - 1], dp2[i - 1] + a);
            dp3[i] = min(dp2[i - 1], dp3[i - 1]) + b;
        } else if (m[i] == 2) {
            dp1[i] = inf;
            dp2[i] = min(a + dp1[i - 1], dp2[i - 1] + a);
            dp3[i] = inf;
        }
    }
    return min(dp1[n - 1], min(dp2[n - 1], dp3[n - 1]));
}

ll solve()///first alive
{
    ll ans = inf;
    for (int d = v[0] - 1; d <= v[0] + 1; ++d) {
        if (d == 1) {
            continue;
        }
        vector<int> primes = factorization(d);
        for (int p : primes) {
            ll relax = (d == v[0] ? 0 : b);
            vector<int> m(n);
            for (int i = 1; i < n; ++i) {
                if (v[i] % p == 0) {
                    m[i] = 0;
                } else if ((v[i] + 1) % p == 0 || (v[i] - 1) % p == 0) {
                    m[i] = 1;
                } else {
                    m[i] = 2;
                }
            }
            relax += f(m);
            /*if (relax == 3) {
                cout << p << " " << f(m) << "\n";
            }*/
            ans = min(ans, relax);
        }
    }
    return ans;
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("division.out");

    cin >> n >> a >> b;

    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    ll ans = solve();
    reverse(all(v));
    ans = min(ans, solve());

    cout << ans << "\n";

}