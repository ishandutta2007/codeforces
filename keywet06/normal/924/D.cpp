#include <bits/stdc++.h>

using int32 = int;
using int64 = long long;
using i5 = int32;
using i6 = int64;
using pi5 = std::pair<i5, i5>;
using pi6i5 = std::pair<i6, i5>;
using pi6 = std::pair<i6, i6>;

#define fir first
#define sec second
#define mkp std::make_pair

const int N = 200005;

struct Bit {
    int a[N];
    void init() { memset(a, 0, sizeof(a)); }
    void modify(int x, int v) {
        for (int i = x; i < N; i += i & -i) a[i] += v;
    }
    int sum(int x) {
        int ans = 0;
        for (int i = x; i; i -= i & -i) ans += a[i];
        return ans;
    }
    int query(int L, int R) {
        if (L > R) return 0;
        return sum(R) - sum(L - 1);
    }
};

struct nd {
    nd(int64 a, int64 b) : a(a), b(b) {}
    bool operator<(const nd& rhs) const { return a * rhs.b < rhs.a * b; }
    bool operator==(const nd& rhs) const { return a * rhs.b == rhs.a * b; }
    void print() { printf("%.5f ", 1.0 * a / b); }
    int64 a, b;
};

int n, w, x[N], v[N];
int64 ans = 0;
std::vector<pi5> vc[2];
std::vector<nd> hs;
Bit bit;

bool cmp(pi5& a, pi5& b) {
    if (a.fir == b.fir) return a.sec < b.sec;
    return a.fir > b.fir;
}

int64 solve(std::vector<pi5>& vc) {
    bit.init();
    int64 ans = 0;
    sort(vc.begin(), vc.end(), cmp);
    for (int i = 0; i < vc.size(); i++) {
        ans += bit.sum(vc[i].sec);
        bit.modify(vc[i].sec, 1);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &v[i]);
        if (x[i] < 0) {
            hs.push_back(nd(-x[i], v[i] + w));
            hs.push_back(nd(-x[i], v[i] - w));
        } else {
            hs.push_back(nd(x[i], w - v[i]));
            hs.push_back(nd(x[i], -w - v[i]));
        }
    }
    sort(hs.begin(), hs.end());
    hs.erase(unique(hs.begin(), hs.end()), hs.end());
    for (int i = 1; i <= n; i++) {
        if (x[i] < 0) {
            int L = lower_bound(hs.begin(), hs.end(), nd(-x[i], v[i] + w)) -
                    hs.begin() + 1;
            int R = lower_bound(hs.begin(), hs.end(), nd(-x[i], v[i] - w)) -
                    hs.begin() + 1;
            vc[0].push_back(mkp(L, R));
        } else {
            int L = lower_bound(hs.begin(), hs.end(), nd(x[i], w - v[i])) -
                    hs.begin() + 1;
            int R = lower_bound(hs.begin(), hs.end(), nd(x[i], -w - v[i])) -
                    hs.begin() + 1;
            vc[1].push_back(mkp(L, R));
        }
    }
    ans += solve(vc[0]);
    ans += solve(vc[1]);
    ans += 1ll * vc[0].size() * vc[1].size();
    bit.init();
    for (auto& t : vc[1]) bit.modify(t.sec, 1);
    for (auto& t : vc[0]) ans -= bit.sum(t.fir - 1);
    bit.init();
    for (auto& t : vc[1]) bit.modify(t.fir, 1);
    for (auto& t : vc[0]) ans -= bit.query(t.sec + 1, N - 1);
    printf("%lld\n", ans);
    return 0;
}