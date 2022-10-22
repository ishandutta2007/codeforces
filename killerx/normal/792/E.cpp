#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

const int mxn = 505;
int n;
int a[mxn];
i64 ans = 1LL << 60;

void check(int S) {
    i64 cur = 0;
    rep(i, n) {
        /*
        int lb = 0, rb = a[i] / S;
        while (lb < rb) {
            int md = (lb + rb) >> 1;
            if (a[i] - md * S <= md) rb = md;
            else lb = md + 1;
        }
        */
        int lb = (a[i] + S) / (S + 1);
        if (a[i] - lb * S >= 0 && a[i] - lb * S <= lb) cur += lb;
        else return ;
    }
    if (cur < ans) ans = cur;
}

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i]);
    for (int S = 1; S <= 40000; ++ S) check(S);
    for (int k = 1; k <= 40000; ++ k) {
        int S = a[0] / k;
        if (S - 1 >= 1) check(S - 1);
        if (S >= 1) check(S);
    }
    printf("%lld\n", ans);
    return 0;
}