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
typedef long double ld;
typedef pair<ld, ld> pld;

const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    ll ans = inf;

    vector<vector<ll> > a(m);
    for (int i = 0; i < n; ++i) {
        int x;
        ll c;
        cin >> x >> c;
        --x;
        a[x].pb(c);
    }

    for (int i = 0; i < m; ++i) {
        sort(all(a[i]));
    }

    for (int x = 1; x <= n; ++x) {
        ll sum = 0;
        vector<ll> rest;
        int cnt = sz(a[0]);
        for (int i = 1; i < m; ++i) {
            if (sz(a[i]) < x) {
                for (ll v : a[i]) {
                    rest.pb(v);
                }
            } else {
                for (int j = 0; j <= sz(a[i]) - x; ++j) {
                    sum += a[i][j];
                    ++cnt;
                }
                for (int j = sz(a[i]) - x + 1; j < sz(a[i]); ++j) {
                    rest.pb(a[i][j]);
                }
            }
        }
        sort(all(rest));
        int ptr = 0;
        while (cnt < x) {
            sum += rest[ptr];
            ++ptr;
            ++cnt;
        }
        ans = min(ans, sum);
    }

    cout << ans << "\n";

}