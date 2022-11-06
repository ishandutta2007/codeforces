#include <bits/stdc++.h>

using namespace std;

int d[10][10];

int n;

int ga(int i, int j) {
    return (j == n) ? 1: ((cin >> d[i][j]), ga(i, j + 1));
}

int fa(int i) {
    return (i == n) ? 1: (ga(i, 0), fa(i + 1));
}

int c(int k, int i, int j) {
    return (j == n) ? 1: (d[i][j] = min(d[i][j], d[i][k] + d[k][j]), c(k, i, j + 1));
}

int b(int k, int i) {
    return (i == n) ? 1: (c(k, i, 0), b(k, i + 1));
}

int a(int k) {
    return (k == n) ? 1: (b(k, 0), a(k + 1));
}

int ans;

int y(int i, int j) {
    return (j == n) ? 1: (ans = max(ans, d[i][j]), y(i, j + 1));
}

int x(int i) {
    return (i == n) ? 1: (y(i, 0), x(i + 1));
}

int main() {
    cin >> n;
    fa(0);
    a(0);
    x(0);
    cout << ans << endl;
}