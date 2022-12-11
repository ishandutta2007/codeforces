#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k, n;
    cin >> k >> n;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(all(t));

    vector<ll> a(n - 1);
    for (int i = 1; i < n; ++i) {
        a[i - 1] = t[i] - t[i - 1];
        //cout << a[i - 1] << " ";
    }
    //cout << "\n";

    vector<pll> v;
    for (int i = 0; i < sz(a); ++i) {
        v.pb({a[i], i});
    }
    sort(all(v));

    vector<pll> b;
    int pr = -2;
    for (int i = 0; i < sz(v) && i < 3 * k + 5; ++i) {
        //cout << v[i].first << " " << v[i].second << "\n";
        b.pb(v[i]);
    }
    sort(all(b), [&] (pll p, pll q) {
        return p.second < q.second;
    });

    vector<pll> c;
    for (int i = 0; i < sz(b); ++i) {
        if (b[i].second == pr + 1) {
            c.pb({b[i].first, 1});
        } else {
            c.pb({b[i].first, 0});
        }
        pr = b[i].second;
    }

    vector<ll> dp0(k + 1, inf);
    vector<ll> dp1(k + 1, inf);
    dp0[0] = 0;

    for (int i = 0; i < sz(c); ++i) {
        vector<ll> nx0(k + 1, inf);
        vector<ll> nx1(k + 1, inf);
        for (int z = 0; z <= k; ++z) {
            if (dp0[z] == inf) {
                continue;
            }
            nx0[z] = min(nx0[z], dp0[z]);
            if (z + 1 <= k) {
                nx1[z + 1] = min(nx1[z + 1], dp0[z] + c[i].first);
            }
        }
        for (int z = 0; z <= k; ++z) {
            if (dp1[z] == inf) {
                continue;
            }
            nx0[z] = min(nx0[z], dp1[z]);
            if (z + 1 <= k && c[i].second == 0) {
                nx1[z + 1] = min(nx1[z + 1], dp1[z] + c[i].first);
            }
        }
        dp0.swap(nx0);
        dp1.swap(nx1);
    }

    cout << min(dp0[k], dp1[k]) << "\n";

}