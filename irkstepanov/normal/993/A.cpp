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

struct pt {
    int x, y;
    pt() {}
    pt(int x, int y) : x(x), y(y) {}
    pt operator-(const pt& other) const {
        return {x - other.x, y - other.y};
    }
};

int cross(const pt& p, const pt& q) {
    return p.x * q.y - p.y * q.x;
}

bool inside(const pt& a, const vector<pt>& p) {
    int x = 0;
    int n = sz(p);
    for (int i = 0; i < n; ++i) {
        x += cross(p[i], p[(i + 1) % n]);
    }
    x = abs(x);
    int y = 0;
    for (int i = 0; i < n; ++i) {
        y += abs(cross(p[i] - a, p[(i + 1) % n] - a));
    }
    return x == y;
}

const int nmax = 150;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<pt> a(4), b(4);
    for (int i = 0; i < 4; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < 4; ++i) {
        cin >> b[i].x >> b[i].y;
    }

    for (int x = -nmax; x <= nmax; ++x) {
        for (int y = -nmax; y <= nmax; ++y) {
            pt p = {x, y};
            if (inside(p, a) && inside(p, b)) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";

}