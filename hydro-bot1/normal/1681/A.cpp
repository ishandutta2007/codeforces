// Hydro submission #62c7c7f6c3a9fda5622c48b7@1657260022740
#include <cstdio>
void solve() {
    int val;
    int n;
    scanf("%d", &n);
    int maxa = -0x7f7f7f7f, maxb = -0x7f7f7f7f;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (val > maxa) maxa = val;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (val > maxb) maxb = val;
    }
    if (maxa > maxb) {
        puts("Alice\nAlice");
    }
    else if (maxa < maxb) {
        puts("Bob\nBob");
    }
    else {
        puts("Alice\nBob");
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}