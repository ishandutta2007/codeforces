#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5, mod = 998244353;
int n, a[mxn];

void Main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i]);
    int ans = 0;
    std::vector <std::pair <int, int> > vec;
    for (int l = n - 1; ~l; -- l) {
        std::vector <std::pair <int, int> > nvec;
        nvec.push_back({a[l], l});
        int p = 0;
        for (int v = a[l]; v; v = a[l] / (a[l] / v + 1)) {
            while (p < (int) vec.size() && (a[l] + vec[p].first - 1) / vec[p].first <= a[l] / v) {
                if (nvec.back().first == v) nvec.back().second = vec[p].second;
                else nvec.push_back({v, vec[p].second});
                ++ p;
            }
        }
        vec = nvec;
        if (l) {
            int last = l;
            for (auto pr : nvec) {
                ans = (ans + 1LL * (l - 0) * ((a[l - 1] + pr.first - 1) / pr.first - 1) % mod * (pr.second - last + 1) % mod) % mod;
                last = pr.second + 1;
            }
        }
    }
    /*
    for (int r = n - 1; ~r; -- r) {
        int v = a[r];
        long long cur = 0;
        for (int l = r; ~l; -- l) {
            int ov = v;
            while ((a[l] + ov - 1) / ov > a[l] / v) -- v;
            cur += (a[l] + ov - 1) / ov;
            eprintf("%d %d %lld\n", l, r, cur - (r - l + 1));
            ans += cur - (r - l + 1);
        }
    }
    */
    printf("%d\n", ans);
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}