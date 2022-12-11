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
typedef pair<int, int> pii;
typedef long double ld;

struct pt {
    ll x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}
    pt operator-(const pt& other) const {
        return {x - other.x, y - other.y};
    }
};

ll cross(const pt& p, const pt& q) {
    return p.x * q.y - p.y * q.x;
}

const int buben = 500;

mt19937 rr(998244353);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    if (n <= 4) {
        cout << "YES\n";
        return 0;
    }

    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    for (int op = 0; op < buben; ++op) {
        int a = rr() % n;
        int b;
        while (true) {
            b = rr() % n;
            if (b == a) {
                continue;
            }
            break;
        }
        vector<pt> rest;
        for (int i = 0; i < n; ++i) {
            if (cross(p[i] - p[a], p[b] - p[a]) != 0) {
                rest.pb(p[i]);
            }
        }
        if (sz(rest) <= 2) {
            cout << "YES\n";
            return 0;
        }
        bool ok = true;
        for (int i = 2; i < sz(rest); ++i) {
            if (cross(rest[i] - rest[1], rest[0] - rest[1]) != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

}