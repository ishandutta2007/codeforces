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
typedef pair<int, int> pii;
typedef long double ld;

ll f(ll x, ll y) {
    if (x < y) {
        return (y - x - 1) * (y - x - 1) - (y - x) * (y - x);
    } else {
        return (x - 1 - y) * (x - 1 - y) - (x - y) * (x - y);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k1, k2;
    cin >> n >> k1 >> k2;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    while (k1--) {
        int pos = 0;
        ll delta = f(a[0], b[0]);
        for (int i = 1; i < n; ++i) {
            ll val = f(a[i], b[i]);
            if (val < delta) {
                pos = i;
                delta = val;
            }
        }
        if (a[pos] < b[pos]) {
            ++a[pos];
        } else {
            --a[pos];
        }
    }

    while (k2--) {
        int pos = 0;
        ll delta = f(b[0], a[0]);
        for (int i = 1; i < n; ++i) {
            ll val = f(b[i], a[i]);
            if (val < delta) {
                pos = i;
                delta = val;
            }
        }
        if (b[pos] < a[pos]) {
            ++b[pos];
        } else {
            --b[pos];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += ll(a[i] - b[i]) * (a[i] - b[i]);
    }
    cout << ans << "\n";

}