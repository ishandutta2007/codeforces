#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll inf = 1e18;

void solve(const vector<ll>& p, vector<ll>& ans, int pos, ll val) {
    ans.pb(val);
    if (pos == sz(p)) {
        return;
    }
    while (true) {
        solve(p, ans, pos + 1, val);
        if (val > inf / p[pos]) {
            break;
        }
        val *= p[pos];
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    ll k;
    cin >> k;

    if (n == 1) {
        ll ans = 1;
        for (int i = 1; i < k; ++i) {
            ans *= p[0];
        }
        cout << ans << "\n";
        return 0;
    }

    int a = min(n / 2, 6);
    int b = n - a;
    vector<ll> x(a), y(b);
    for (int i = 0; i < a; ++i) {
        x[i] = p[i];
    }
    for (int i = 0; i < b; ++i) {
        y[i] = p[i + a];
    }

    vector<ll> lf, rg;
    solve(x, lf, 0, 1);
    solve(y, rg, 0, 1);

    sort(all(lf));
    sort(all(rg));
    lf.resize(unique(all(lf)) - lf.begin());
    rg.resize(unique(all(rg)) - rg.begin());
    //cout << sz(lf) << " " << sz(rg) << endl;

    ll l = 0, r = inf;

    while (r - l > 1) {
        ll m = (l + r) >> 1;
        ll cnt = 0;
        int ptr = sz(rg) - 1;
        for (ll u : lf) {
            if (u > m) {
                break;
            }
            while (u > m / rg[ptr]) {
                --ptr;
            }
            cnt += ptr + 1;
        }
        if (cnt >= k) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << "\n";

}