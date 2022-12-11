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

int x[2];
int y[2];
vector<int> p;

void solve() {
    for (int u = 0; u < 2; ++u) {
        for (int v = 0; v < 2; ++v) {
            if (x[u] == y[v] && x[u ^ 1] != y[v ^ 1]) {
                p.pb(x[u]);
            }
        }
    }
}

void f() {
    sort(all(p));
    p.resize(unique(all(p)) - p.begin());
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pii> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].first >> b[i].second;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            x[0] = a[i].first, x[1] = a[i].second;
            y[0] = b[j].first, y[1] = b[j].second;
            solve();
        }
    }

    f();
    if (sz(p) == 1) {
        cout << p[0] << "\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            p.clear();
            x[0] = a[i].first, x[1] = a[i].second;
            y[0] = b[j].first, y[1] = b[j].second;
            solve();
            f();
            if (sz(p) != 1) {
                continue;
            }
            bool ok = true;
            p.clear();
            for (int jj = 0; jj < m; ++jj) {
                x[0] = a[i].first, x[1] = a[i].second;
                y[0] = b[jj].first, y[1] = b[jj].second;
                solve();
            }
            f();
            if (sz(p) != 1) {
                ok = false;
            }
            p.clear();
            for (int ii = 0; ii < n; ++ii) {
                x[0] = a[ii].first, x[1] = a[ii].second;
                y[0] = b[j].first, y[1] = b[j].second;
                solve();
            }
            f();
            if (sz(p) != 1) {
                ok = false;
            }
            if (!ok) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << "0\n";

}