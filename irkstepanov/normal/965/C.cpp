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
#include <bitset>
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

int main() {

    ll n, k, m, d;
    cin >> n >> k >> m >> d;

    ll ans = 0;

    for (int t = 1; t <= d; ++t) {
        ll rg = m;
        if (t > 1) {
            rg = min(rg, n / (k * (t - 1) + 1));
        }
        if (rg < 1) {
            break;
        }
        ll lf = n / (k * t + 1) + 1;
        if (lf <= rg) {
            ans = max(ans, rg * t);
        }
    }

    cout << ans << "\n";

}