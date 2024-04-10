#include <bits/stdc++.h>

using int64 = long long;

const int N = 200005;

int n;

int64 c;
int64 s[N], pp[N], pref[N];

bool okay(int64 amm, int stp) {
    int lw = 0, hg = n - stp + 1;
    while (lw < hg) {
        int mid = (lw + hg + 1) / 2;
        if (pp[stp + mid - 1] - pp[stp - 1] > amm) {
            hg = mid - 1;
        } else {
            lw = mid;
        }
    }
    amm -= (pp[stp + lw - 1] - pp[stp - 1]);
    if (amm == 0) return true;
    lw = stp + lw, hg = n + 1;
    while (lw < hg) {
        int mid = (lw + hg) / 2;
        if (s[mid] > amm) {
            lw = mid + 1;
        } else {
            hg = mid;
        }
    }
    if (lw == n + 1) return false;
    return okay(amm, lw);
}

void init() {
    scanf("%I64d%d", &c, &n);
    for (int i = 1; i <= n; ++i) scanf("%I64d", &s[i]);
    std::sort(s + 1, s + n + 1, [&](int64 x, int64 y) { return x > y; });
    s[n + 1] = 0;
    pp[0] = pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pp[i] = pp[i - 1] + s[i];
        if (pref[i - 1] + s[i] <= c) {
            pref[i] = pref[i - 1] + s[i];
        } else
            pref[i] = pref[i - 1];
    }
}

void process() {
    for (int i = n - 1; i >= 0; i--) {
        int64 lb = s[i + 1], hb = s[i];
        if (i == 0) hb = c - 1;
        for (int j = lb; j <= hb; ++j) {
            int64 tmpc = c - pref[i];
            if (tmpc >= j) tmpc -= j;
            if (!okay(tmpc, i + 1)) return void(printf("%d\n", j));
        }
    }
    printf("Greed is good\n");
}

int main() {
    init(), process();
    return 0;
}