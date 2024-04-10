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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct pt {
    ld x, y, z;
};

ld dist(const pt& a, const pt& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].z;
    }

    ld ans = 1e18;

    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ld a = dist(p[0], p[i]);
            ld b = dist(p[0], p[j]);
            ld c = dist(p[i], p[j]);
            ld x = (c + b - a) / 2;
            ans = min(ans, a + x);
        }
    }

    cout << fixed;
    cout.precision(20);
    cout << ans << "\n";

}