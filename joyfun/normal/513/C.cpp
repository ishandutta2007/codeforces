#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10;

int n;
int L[N], R[N];

int bitcount(int x) {
if (x == 0)return 0;
return bitcount(x / 2) + (x % 2);
}
double cal(int win, int bid, int s) {
    if (bitcount(s) == 1 && bid == n) return 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (R[i] >= win) cnt++;
    if (cnt < 2) return 0;
    double p = 1.0;
    if (bid != n) {
        if (R[bid] <= win) return 0;
        p *= (R[bid] - max(win + 1, L[bid]) + 1) * 1.0 / (R[bid] - L[bid] + 1);
    }
    for (int i = 0; i < n; i++) {
        if (i == bid) continue;
        if (s&(1<<i)) {
            if (win < L[i] || win > R[i]) return 0;
            p *= 1.0 / (R[i] - L[i] + 1);
        } else {
            if (L[i] > win) return 0;
            p *= (min(R[i], win - 1) - L[i] + 1) * 1.0 / (R[i] - L[i] + 1);
        }
    }
    return p * win;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &L[i], &R[i]);
    double ans = 0;
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 1; k < (1<<n); k++) {
                if (k&(1<<j)) continue;
                ans += cal(i, j, k);
            }
        }
    }
    printf("%.10f\n", ans);
    return 0;
}