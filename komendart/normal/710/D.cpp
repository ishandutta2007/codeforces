#include <bits/stdc++.h>

using namespace std;

#define int long long

#define div sdofkjdsi
int div(int x, int y) {
    if (y < 0) {
        x = -x;
        y = -y;
    }
    int mod = (x % y + y) % y;
    return (x - mod) / y;
}

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (a && b) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

void gcdex(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return;
    }
    int x1, y1;
    gcdex(b - a * div(b, a), a, x1, y1);
    x = y1 - div(b, a) * x1;
    y = x1;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int a1, b1, a2, b2, L, R;
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;

    L = div(L - b1 + a1 - 1, a1);
    R = div(R - b1, a1);

    int A = a1;
    int B = -a2;
    int C = b2 - b1;

    int g = gcd(A, B);
    if (C % g != 0) {
        cout << 0 << '\n';
        return 0;
    }
    A /= g;
    B /= g;
    C /= g;

    L = max(0LL, L);
    L = max(div(C + A - 1, A), L);

    int x, y;
    gcdex(A, B, x, y);
    x *= C; y *= C;

    B = abs(B);
    L = div(L - x + B - 1, B);
    R = div(R - x, B);
    cout << max(0LL, R - L + 1) << '\n';
}