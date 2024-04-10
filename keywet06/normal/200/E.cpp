#include <bits/stdc++.h>

using namespace std;

const int C = 10;
const int N = 1000000000;

int n, s, x, I, J, K, a, t;
int c[C];

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; ++i) scanf("%d", &x), ++c[x];
    a = N;
    for (int i = s / n; i >= 0; --i)
        for (int j = (s - c[3] * i) / (n - c[3]); j >= i; --j) {
            int k = (s - c[3] * i - c[4] * j) / c[5];
            if (k * c[5] - j * c[4] >= a) break;
            if (i * c[3] + j * c[4] + k * c[5] == s &&
                a > (t = abs(i * c[3] - j * c[4]) + abs(j * c[4] - k * c[5]))) {
                a = t, I = i, J = j, K = k;
            }
        }
    if (a != N) {
        printf("%d %d %d\n", I, J, K);
    } else {
        puts("-1");
    }
    return 0;
}