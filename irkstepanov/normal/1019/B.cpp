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

int get(int pos) {
    cout << "? " << pos << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void print(int pos) {
    cout << "! " << pos << "\n";
    cout.flush();
    exit(0);
}

bool inter(int a, int b, int x, int y) {
    int u;
    if (a < x) {
        u = 1;
    } else {
        u = -1;
    }
    int v;
    if (b < y) {
        v = 1;
    } else {
        v = -1;
    }
    return u * v < 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    if (n % 4) {
        cout << "! -1\n";
        cout.flush();
        return 0;
    }

    int x = get(1);
    int y = get(1 + n / 2);

    if (x == y) {
        print(1);
    }

    int a = get(1 + 3 * n / 4);
    int b = get(1 + n / 4);
    if (a == b) {
        print(1 + n / 4);
    }

    int l1, r1, l2, r2;
    int x1, y1, x2, y2;

    if (inter(a, x, b, y)) {
        l1 = 3 * n / 4, r1 = n;
        x1 = a, y1 = x;
        l2 = n / 4, r2 = n / 2;
        x2 = b, y2 = y;
    } else {
        assert(inter(x, b, y, a));
        l1 = 0, r1 = n / 4;
        x1 = x, y1 = b;
        l2 = n / 2, r2 = 3 * n / 4;
        x2 = y, y2 = a;
    }

    while (true) {
        int m1 = (l1 + r1) >> 1;
        int m2 = (l2 + r2) >> 1;
        int z1 = get(m1 + 1);
        int z2 = get(m2 + 1);
        if (z1 == z2) {
            print(min(m1, m2) + 1);
        }
        if (inter(x1, z1, x2, z2)) {
            y1 = z1, y2 = z2;
            r1 = m1, r2 = m2;
        } else {
            assert(inter(z1, y1, z2, y2));
            x1 = z1, x2 = z2;
            l1 = m1, l2 = m2;
        }
    }

}