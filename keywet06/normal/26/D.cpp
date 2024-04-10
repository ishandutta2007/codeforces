#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

double fac[N];

int a, b, c;

double solve() {
    if (a + c < b) return 0;
    if (b < c) return 1;
    double ret = fac[a] + fac[b] - fac[a + c] - fac[b - c];
    if (ret < -10) return 1.0;
    return 1.0 - pow(10.0, ret);
}

int main() {
    fac[0] = 0;
    for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] + log10((double)i);
    cin >> a >> b >> c, ++c;
    cout << solve() << endl;
    return 0;
}