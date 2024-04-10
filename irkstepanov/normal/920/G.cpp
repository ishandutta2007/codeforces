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
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 1e6 + 100;
const ll inf = 1e18;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

bool prime[nmax];
int mind[nmax];
vector<int> primes;

ll solve(ll x, const vector<int>& d) {
    ll ans = 0;
    int n = sz(d);
    for (int mask = 0; mask < (1 << n); ++mask) {
        ll val = 1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (bit(mask, i)) {
                val *= d[i];
                cnt ^= 1;
            }
        }
        if (cnt == 0) {
            ans += (x / val);
        } else {
            ans -= (x / val);
        }
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i = 0; i < nmax; ++i) {
        prime[i] = true;
        mind[i] = i;
    }
    for (int i = 2; i < nmax; ++i) {
        if (prime[i]) {
            primes.pb(i);
            for (int j = i * 2; j < nmax; j += i) {
                prime[j] = false;
                mind[j] = min(mind[j], i);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        ll x, m, k;
        cin >> x >> m >> k;
        vector<int> d;
        while (m > 1) {
            int p = mind[m];
            d.pb(p);
            while (m % p == 0) {
                m /= p;
            }
        }
        ll lf = 0, rg = inf;
        ll u = solve(x, d);
        while (rg - lf > 1) {
            ll md = (lf + rg) >> 1;
            ll cnt = solve(md, d) - u;
            if (cnt >= k) {
                rg = md;
            } else {
                lf = md;
            }
        }
        cout << rg << "\n";
    }

}