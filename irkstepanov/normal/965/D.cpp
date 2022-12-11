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

const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n + 1);
    a[0] = inf;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
    }
    a[n] = inf;

    vector<ll> pref(n + 1);
    pref[0] = a[0];
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }

    ll ans = inf;
    for (int i = k - 1; i <= n; ++i) {
        ll sum = pref[i];
        if (i - k + 1 > 0) {
            sum -= pref[i - k];
        }
        //cout << i << " " << sum << "\n";
        ans = min(ans, sum);
    }
    cout << ans << "\n";

}