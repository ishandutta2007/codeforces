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

    int n, k;
    cin >> n >> k;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int> > cnt(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + k - 1 < n; ++j) {
            bool ok = true;
            for (int s = 0; s < k; ++s) {
                if (a[i][j + s] == '#') {
                    ok = false;
                }
            }
            if (ok) {
                for (int s = 0; s < k; ++s) {
                    ++cnt[i][j + s];
                }
            }
        }
    }

    for (int i = 0; i + k - 1 < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool ok = true;
            for (int s = 0; s < k; ++s) {
                if (a[i + s][j] == '#') {
                    ok = false;
                }
            }
            if (ok) {
                for (int s = 0; s < k; ++s) {
                    ++cnt[i + s][j];
                }
            }
        }
    }

    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (cnt[i][j] > cnt[x][y]) {
                x = i, y = j;
            }
        }
    }

    cout << x + 1 << " " << y + 1 << "\n";

}