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

bool ok(pii p, int n, int m, vector<int> cnt) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int d = abs(p.first - i) + abs(p.second - j);
            --cnt[d];
        }
    }
    for (int i = 0; i < sz(cnt); ++i) {
        if (cnt[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    vector<int> cnt(t);
    for (int i = 0; i < t; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    int maxx = 0;
    for (int i = 1; i < t; ++i) {
        if (cnt[i]) {
            maxx = i;
        }
    }

    int f = 1;
    while (cnt[f] == 4 * f) {
        ++f;
    }

    for (int n = 1; n * n <= t; ++n) {
        if (t % n) {
            continue;
        }
        int m = t / n;
        vector<pii> valid;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (abs(i - 0) + abs(j - 0) != maxx) {
                    continue;
                }
                if (i + (f - 1) >= n) {
                    continue;
                }
                if (i - (f - 1) < 0) {
                    continue;
                }
                if (j + (f - 1) >= m) {
                    continue;
                }
                if (j - (f - 1) < 0) {
                    continue;
                }
                if (i + f < n && i - f >= 0 && j + f < m && j - f >= 0) {
                    continue;
                }
                valid.pb({i, j});
            }
        }
        for (pii p : valid) {
            if (ok(p, n, m, cnt)) {
                cout << n << " " << m << "\n";
                cout << p.first + 1 << " " << p.second + 1 << "\n";
                return 0;
            }
        }
    }

    cout << "-1\n";

}