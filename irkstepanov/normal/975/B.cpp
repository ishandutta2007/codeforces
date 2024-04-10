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

const int n = 14;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<ll> b = a;
        ll val = b[i];
        b[i] = 0;
        ll z = val / n;
        for (int j = 0; j < n; ++j) {
            b[j] += z;
        }
        val %= n;
        int pos = (i + 1) % n;
        while (val) {
            ++b[pos];
            pos = (pos + 1) % n;
            --val;
        }
        ll curr = 0;
        for (int j = 0; j < n; ++j) {
            if (b[j] % 2 == 0) {
                curr += b[j];
            }
        }
        ans = max(ans, curr);
    }

    cout << ans << "\n";

}