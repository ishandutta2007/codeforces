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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

vector<ll> pref;

ll getSum(int l, int r) {
    if (l > r) {
        return 0;
    }
    ll ans = pref[r];
    if (l) {
        ans -= pref[l - 1];
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    pref.pb(a[0]);
    for (int i = 1; i < n; ++i) {
        pref.pb(pref.back());
        pref.back() += a[i];
    }

    int first = 0;
    ll val = a[0];

    while (q--) {
        ll x;
        cin >> x;
        ll sum = getSum(first + 1, n - 1) + val;
        if (sum <= x) {
            cout << n << "\n";
            first = 0;
            val = a[0];
            continue;
        }
        if (val > x) {
            val -= x;
            cout << n - first << "\n";
            continue;
        }
        x -= val;
        ++first;
        int lf = first - 1, rg = n - 1;
        //cout << "?" << getSum(1, 1) << endl;
        while (rg - lf > 1) {
            int md = (lf + rg) >> 1;
            //cout << "!" << first << " " << md << " " << getSum(first, md) << "\n";
            if (getSum(first, md) > x) {
                rg = md;
            } else {
                lf = md;
            }
        }
        x -= getSum(first, rg - 1);
        first = rg;
        val = a[first] - x;
        cout << n - first << "\n";
    }

}