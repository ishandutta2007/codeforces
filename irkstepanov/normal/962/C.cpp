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

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

bool sq(ll val) {
    ll lf = 0, rg = val + 1;
    while (rg  - lf > 1) {
        ll md = (lf + rg) >> 1;
        if (md * md <= val) {
            lf = md;
        } else {
            rg = md;
        }
    }
    return lf * lf == val;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    vector<int> d;
    while (n) {
        d.pb(n % 10);
        n /= 10;
    }
    reverse(all(d));

    int k = sz(d);
    int ans = -1;
    for (int mask = 1; mask < (1 << k); ++mask) {
        ll val = 0;
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            if (bit(mask, i)) {
                ++cnt;
                if (val == 0 && d[i] == 0) {
                    val = -1;
                    break;
                }
                val *= 10;
                val += d[i];
            }
        }
        if (val == -1) {
            continue;
        }
        if (sq(val)) {
            ans = max(ans, cnt);
        }
    }

    if (ans == -1) {
        cout << "-1\n";
    } else {
        cout << k - ans << "\n";
    }

}