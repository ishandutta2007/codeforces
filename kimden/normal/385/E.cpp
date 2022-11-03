#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int n;
inline int add(int x, int y) {
    int z = x + y;
    if (z >= n) {
        z -= n;
    }
    return z;
}
inline int sub(int x, int y) {
    int z = x + n - y;
    if (z >= n) {
        z -= n;
    }
    return z;
}
inline int mul(int x, int y) {
    return (x * (ll)y) % n;
}
void make(int dest[6][6], int val) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            dest[i][j] = (i == j ? val : 0) % n;
        }
    }
}
void cp(int dest[6][6], int src[6][6]) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            dest[i][j] = src[i][j];
        }
    }
}
void mul(int dest[6][6], int left[6][6], int right[6][6]) {
    int tmp[6][6];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            tmp[i][j] = 0;
            for (int k = 0; k < 6; ++k) {
                tmp[i][j] = add(tmp[i][j], mul(left[i][k], right[k][j]));
            }
        }
    }
    cp(dest, tmp);
}

int a[6][6];
int b[6][6];
int c[6][6];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, dx, dy;
    ll t;
    cin >> n >> x >> y >> dx >> dy >> t;
    x %= n;
    y %= n;
    dx %= n;
    dx += n;
    dx %= n;
    dy %= n;
    dy += n;
    dy %= n;
    vector<int> v = {2, 1, 1, 0, 1, 0,
                     1, 2, 0, 1, 1, 0,
                     1, 1, 1, 0, 1, 0,
                     1, 1, 0, 1, 1, 0,
                     0, 0, 0, 0, 1, 1,
                     0, 0, 0, 0, 0, 1};
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            a[i][j] = v[i * 6 + j] % n;
        }
    }
    make(b, 1 % n);
    while (t) {
        if (t & 1LL) {
            mul(b, b, a);
        }
        mul(a, a, a);
        t >>= 1LL;
    }
    vector<int> rhs = {x, y, dx, dy, 0, 1 % n};
    int new_x = 0;
    int new_y = 0;
    for (int i = 0; i < 6; ++i) {
        new_x = add(new_x, mul(b[0][i], rhs[i]));
        new_y = add(new_y, mul(b[1][i], rhs[i]));
    }
    if (new_x == 0) {
        new_x += n;
    }
    if (new_y == 0) {
        new_y += n;
    }
    cout << new_x << " " << new_y << "\n";
}