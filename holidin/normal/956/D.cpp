#include <cstdio>
#include <algorithm>
#include <utility>

typedef long long int64;
static const int MAXN = 1e5 + 4;
static const int MAXX = 1e8 + 4;

static int n, w;
static int x[MAXN], v[MAXN];

struct fraction {
    template <typename T> static inline T gcd(const T a, const T b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    int64 num, deno;
    inline void simplify() {
        if (deno < 0) { num *= -1; deno *= -1; }
        int64 g = gcd(num < 0 ? -num : num, deno); num /= g; deno /= g;
    }

    fraction() { }
    fraction(int64 num, int64 deno) : num(num), deno(deno) { simplify(); }

    inline bool operator < (const fraction &rhs) const {
        return num * rhs.deno < deno * rhs.num;
    }
    inline bool operator != (const fraction &rhs) const {
        return num * rhs.deno != deno * rhs.num;
    }
};

// Time bounds at which clouds can arrive at the origin
static std::pair<fraction, fraction> t[MAXN];
// Used at discretization
static std::pair<fraction, int> d[MAXN];
static int p[MAXN];

struct bit {
    static const int MAXN = ::MAXN;
    int f[MAXN];
    bit() { std::fill(f, f + MAXN, 0); }
    inline void add(int pos, int inc) {
        for (++pos; pos < MAXN; pos += (pos & -pos)) f[pos] += inc;
    }
    inline int sum(int rg) {
        int ans = 0;
        for (++rg; rg; rg -= (rg & -rg)) ans += f[rg];
        return ans;
    }
    inline int sum(int lf, int rg) {
        return sum(rg) - sum(lf - 1);
    }
} arkady;

int main()
{
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &v[i]);

    for (int i = 0; i < n; ++i) {
        int64 v1 = v[i] - w, v2 = v[i] + w;
        t[i] = {fraction(-x[i], v1), fraction(-x[i], v2)};
    }

    for (int i = 0; i < n; ++i) t[i].second.num *= -1;
    std::sort(t, t + n);
    for (int i = 0; i < n; ++i) t[i].second.num *= -1;
    for (int i = 0; i < n; ++i) d[i] = {t[i].second, i};
    std::sort(d, d + n);
    for (int i = 0, rk = -1; i < n; ++i) {
        if (i == 0 || d[i].first != d[i - 1].first) ++rk;
        p[d[i].second] = rk;
    }
    /*for (int i = 0; i < n; ++i)
        printf("%.4lf %.4lf | %d\n",
            (double)t[i].first.num / t[i].first.deno,
            (double)t[i].second.num / t[i].second.deno, p[i]);*/

    int64 ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += arkady.sum(p[i], MAXN - 1);
        arkady.add(p[i], 1);
    }

    printf("%lld\n", ans);

    return 0;
}