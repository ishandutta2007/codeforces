#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;
template<typename T>
inline void maxify(T& lhs, const T& rhs) { lhs = max(lhs, rhs); }
template<typename T>
inline void minify(T& lhs, const T& rhs) { lhs = min(lhs, rhs); }
constexpr int inf = 2000000000;
struct Vfunc {
    int c, v;
    Vfunc() {}
    Vfunc(int cc, int vv) : c(cc), v(vv) {}
    int get(int x) { return v + abs(x - c); }
};
Vfunc max(Vfunc lhs, Vfunc rhs) {
    int maxs = max(lhs.v + lhs.c, rhs.v + rhs.c);
    int maxd = max(lhs.v - lhs.c, rhs.v - rhs.c);
    return Vfunc((maxs - maxd) / 2, (maxs + maxd) / 2);
}
struct Magic {
    int maxx, maxxv, maxs;
    Magic() : maxx(-inf), maxxv(-inf), maxs(-inf) {}
    Vfunc op(int addend, int newx) {
        newx /= 2;
        if(newx > maxx) {
            maxx = newx;
            maxxv = 0;
        }
        if(newx > maxs)
            maxs = newx;
        if(maxxv < 0) {
            maxxv = 0;
            maxify(maxs, maxx + maxxv);
        }
        maxxv += addend;
        maxs += addend;
        return Vfunc(maxs - maxx, maxs + maxx);
    }
};
int a[30000];
Vfunc dp[200][30001];
int solve(int n, int k) {
    {
        int maxmax = -inf, minmin = inf, maxs = 0, mins = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(maxs < 0) maxs = 0;
            if(mins > 0) mins = 0;
            maxs += a[i];
            mins += a[i];
            maxify(maxmax, maxs);
            minify(minmin, mins);
            dp[0][i] = max(Vfunc(maxmax, 0), Vfunc(minmin, 0));
        }
    }
    for(int ki = 1; ki < k - 1; ki++) {
        Magic magic1, magic2;
        for(int ai = n - ki - 1; ai >= 0; ai--) {
            Vfunc f = dp[ki - 1][ai + 1];
            Vfunc ans1 = magic1.op(a[ai], f.v - f.c);
            Vfunc nans2 = magic2.op(-a[ai], f.v + f.c);
            Vfunc ans2 = Vfunc(-nans2.c, nans2.v);
            dp[ki][ai] = max(ans1, ans2);
            if(ai < n - ki - 1)
                maxify(dp[ki][ai], dp[ki][ai + 1]);
        }
    }

    int ans = 0, maxs = 0, mins = 0;
    for(int i = 0; i <= n - k; i++) {
        if(maxs < 0) maxs = 0;
        if(mins > 0) mins = 0;
        maxs += a[i];
        mins += a[i];
        maxify(ans, dp[k - 2][i + 1].get(maxs));
        maxify(ans, dp[k - 2][i + 1].get(mins));
    }
    return ans;
}
int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) == 2) {
        for(int i = 0; i < n; i++) {
            scanf("%d", a + i);
            a[i] *= 2;
        }
        printf("%d\n", solve(n, k) / 2);
    }
}