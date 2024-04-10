#include <cstdio>
using namespace std;
double expv(int l1, int r1, int l2, int r2, int p) {
    return 1 - (1 - (double) (r1 / p - l1 / p) / (r1 - l1)) *
               (1 - (double) (r2 / p - l2 / p) / (r2 - l2));
}
int main() {
    int n, p;
    scanf("%d %d", &n, &p);

    int l0, r0;
    scanf("%d %d", &l0, &r0);
    l0--;

    int ll = l0, rl = r0;
    double ans = 0;
    for(int i = 1; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;

        ans += expv(ll, rl, l, r, p);
        ll = l;
        rl = r;
    }
    ans += expv(ll, rl, l0, r0, p);
    printf("%.9f\n", ans * 2000);
}