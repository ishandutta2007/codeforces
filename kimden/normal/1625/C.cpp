// hello from kimden
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1002003004;

// i am unable to code cht from scratch sorry
// here goes trd
const ll is_query = -(1LL << 62);
struct Line {
    ll k, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query)
            return k < rhs.k;
        const Line* s = succ();
        return s ? b - s->b < (s->k - k) * rhs.k : 0;
    }
};
// will maintain upper hull for maximum
struct HullDynamic : public multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return false;
            return y->k == z->k && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->k == x->k && y->b <= x->b;
        return (x->b - y->b) * (z->k - y->k) >= (y->b - z->b) * (y->k - x->k);
    }
    void insert_line(int k, int b) {
        auto y = insert({k, b});
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        y->succ = [=]{ return next(y) == end() ? nullptr : &*next(y); };
        while (y != begin() && bad(prev(y))) erase(prev(y));
        if (y != begin()) prev(y)->succ = [=]{ return &*y; };
    }
    ll eval(ll x) {
        if (empty())
            return -INF;
        auto l = *lower_bound((Line){x, is_query});
        return l.k * x + l.b;
    }
};
// end of trd

int dp[2][505];

int main() {
    ios_base::sync_with_stdio(false);
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> d(n), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    d.push_back(l);
    a.push_back(0);
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = INF;
    }
    dp[0][0] = 0;
    int cur = 0;
    int nxt = 1;
    int ans = INF;
    for (int i = 0; i <= n; ++i) {
        if (i >= n - k) {
            ans = min(ans, dp[cur][n]);
        }
        if (i == n) {
            break;
        }
        HullDynamic hull;
        for (int j = 0; j <= n; ++j) {
            dp[nxt][j] = -hull.eval(d[j]);
            // dp[cur][j] + (x - d[j]) * a[j]
            if (dp[cur][j] != INF)
                hull.insert_line(-a[j], a[j] * d[j] - dp[cur][j]);
            // how convenient, a * d <= 1e9
        }
        cur ^= 1;
        nxt ^= 1;
    }
    cout << ans << "\n";
}