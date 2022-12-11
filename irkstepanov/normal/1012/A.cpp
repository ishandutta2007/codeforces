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
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const ll inf = 1e18 + 100;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ll> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }
    sort(all(a));

    ll ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);

    for (int i = 1; i + n - 1 < 2 * n - 1; ++i) {
        ans = min(ans, (a.back() - a[0]) * (a[i + n - 1] - a[i]));
    }
    cout << ans << "\n";

}