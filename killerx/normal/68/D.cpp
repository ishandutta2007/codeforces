#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int h, q;
map <int, int> sum, cnt;

void update(int u, int w) {
    cnt[u] += w;
    while (u) {
        sum[u] += w;
        u >>= 1;
    }
}

double query(int u, int mx, double p) {
    if (u >= (1 << h)) return max(mx, cnt[u]) * p;
    int lsz = sum[u << 1] + cnt[u];
    int rsz = sum[u << 1 | 1] + cnt[u];
    if (lsz < rsz)
        return query(u << 1 | 1, max(mx, lsz), p * 0.5) + max(mx, rsz) * p * 0.5;
    else
        return query(u << 1, max(mx, rsz), p * 0.5) + max(mx, lsz) * p * 0.5;
}

int main() {
    scanf("%d %d", &h, &q);
    while (q --) {
        char op[15];
        scanf("%s", op);
        if (op[0] == 'a') {
            int u, w;
            scanf("%d %d", &u, &w);
            update(u, w);
        } else {
            printf("%.10f\n", query(1, 0, 1));
        }
    }
    return 0;
}