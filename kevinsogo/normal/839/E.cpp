#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int H = 20;

ll adj[H << 1];
ll lahatl[1 << H], lahatr[1 << H];
int best[1 << H], bitc[1 << H];
int main() {
    for (int i = 1; i < 1 << H; i++) {
        bitc[i] = bitc[i >> 1] + (i & 1);
    }
    int n; double k;
    scanf("%d%lf", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v;
            scanf("%d", &v);
            adj[i] |= ll(v || (i == j)) << j;
        }
    }
    int h = n >> 1;
    lahatl[0] = (1LL << n) - 1;
    for (int i = 0; i < h; i++) {
        for (ll m = 0; m < 1 << i; m++) {
            lahatl[m | (1 << i)] = lahatl[m] & adj[i];
        }
    }
    lahatr[0] = (1LL << n) - 1;
    for (int i = 0; i < n - h; i++) {
        for (ll m = 0; m < 1 << i; m++) {
            lahatr[m | (1 << i)] = lahatr[m] & (adj[i + h] >> h);
        }
    }
    for (ll m = 0; m < 1 << n - h; m++) {
        if ((lahatr[m] & m) == m) {
            best[m] = bitc[m];
        } else {
            best[m] = 0;
            for (int i = 0; i < n - h; i++) {
                if (m & (1 << i)) {
                    best[m] = max(best[m], best[m ^ (1 << i)]);
                }
            }
        }
    }
    int ans = 0;
    for (int m = 0; m < 1 << h; m++) {
        if ((lahatl[m] & m) == m) {
            ans = max(ans, bitc[m] + best[lahatl[m] >> h]);
        }
    }
    printf("%.11lf\n", k * k * 0.5 * (1 - 1.0 / ans));
}