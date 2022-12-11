#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

const ll inf = 1e18;
const int nmax = 2e5 + 10;

int main()
{

    //freopen("input.txt", "r", stdin);

    int n, k;
    scanf("%d%d", &n, &k);

    vector<vector<ll> > e(nmax);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        e[x].pb((ll)y);
    }

    int upper = 0;
    for (int i = 1; i < nmax; ++i) {
        upper += sz(e[i]);
    }
    int argue = sz(e[0]);

    ll ans = inf;
    int s;

    for (s = 0; s <= n; ++s) {
        if (upper < k && upper + argue - k + 1 <= s) {
            break;
        }
        upper -= sz(e[s + 1]);
        argue += sz(e[s + 1]);
        if (s - 1 >= 0) {
            argue -= sz(e[s - 1]);
        }
    }

    if (s == n + 1) {
        cout << "-1\n";
        return 0;
    }

    for (int w = max(s - 5, 0); w <= min(s + 5, n); ++w) {
        vector<ll> a, b, c;
        for (int i = 0; i < nmax; ++i) {
            for (ll j : e[i]) {
                if (i > w) {
                    a.pb(j);
                } else if (i == w || i == w - 1) {
                    b.pb(j);
                } else {
                    c.pb(j);
                }
            }
        }
        sort(all(a));
        sort(all(b));
        sort(all(c));
        upper = sz(a);
        if (upper >= k) {
            continue;
        }
        argue = sz(b);
        int kill = upper + argue - k + 1;
        if (kill <= w) {
            if (kill < 0) {
                kill = 0;
            }
            ll relax = 0;
            for (int i = 0; i < kill; ++i) {
                relax += b[i];
            }
            vector<ll> d = a;
            for (int i = kill; i < argue; ++i) {
                d.pb(b[i]);
            }
            for (ll j : c) {
                d.pb(j);
            }
            sort(all(d));
            for (int i = 0; i < w - kill; ++i) {
                relax += d[i];
            }
            ans = min(ans, relax);
        }
    }

    cout << (ans == inf ? -1 : ans) << "\n";

}