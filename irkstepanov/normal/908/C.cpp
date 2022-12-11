#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const ld eps = 1e-9;

bool eq(ld a, ld b) {
    return abs(a - b) <= eps;
}

bool lt(ld a, ld b) {
    return b - a > eps;
}

bool gt(ld a, ld b) {
    return a - b > eps;
}

bool leq(ld a, ld b) {
    return lt(a, b) || eq(a, b);
}

bool geq(ld a, ld b) {
    return gt(a, b) || eq(a, b);
}

struct pt {
    ld x, y;
    pt() {}
    pt(ld x, ld y) : x(x), y(y) {}
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    ld r;
    cin >> n >> r;

    vector<ld> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<ld> y(n);
    for (int i = 0; i < n; ++i) {
        y[i] = r;
        for (int j = 0; j < i; ++j) {
            ld d = abs(x[i] - x[j]);
            if (gt(d, r * 2)) {
                continue;
            }
            ld z = sqrt(r * r * 4 - d * d);
            y[i] = max(y[i], y[j] + z);
        }
    }

    cout << fixed;
    cout.precision(20);
    for (int i = 0; i < n; ++i) {
        cout << y[i] << " ";
    }
    cout << "\n";

}