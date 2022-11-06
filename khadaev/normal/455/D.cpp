#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1e5 + 10;

struct SQRT {
    int sz, n;
    vector<int> a;
    vector<vector<int>> data, cnt;
    vector<pair<int, int>> ops;

    SQRT () {}

    SQRT (int _sz, vector<int> _a) : sz(_sz), n(_a.size()), a(_a) {}

    void build() {
        for (auto p : ops) {
            cnt[p.fs][p.sn] = 0;
        }
        ops.clear();
        data.clear();
        forn(i, 0, n) {
            if (i % sz == 0) data.eb(vector<int>(0));
            data.back().eb(a[i]);
        }
        forn(i, 0, data.size()) {
            for (int x : data[i]) {
                ++cnt[i][x];
                ops.eb(i, x);
            }
        }
    }

    void rebuild() {
        a.clear();
        for (auto x : data) {
            a.insert(a.end(), all(x));
        }
        build();
    }

    int erase(int pos) {
        forn(i, 0, data.size()) {
            auto& x = data[i];
            if (pos < x.size()) {
                int ans = x[pos];
                x.erase(x.begin() + pos);
                --cnt[i][ans];
                ops.eb(i, ans);
                return ans;
            }
            pos -= x.size();
        }
        assert(false);
    }

    void insert(int pos, int val) {
        forn(i, 0, data.size()) {
            auto& x = data[i];
            if (pos <= (int)x.size()) {
                ++cnt[i][val];
                ops.eb(i, val);
                x.insert(x.begin() + pos, val);
                return;
            }
            pos -= x.size();
        }
        assert(false);
    }

    int get(int l, int r, int k) {
        int ans = 0;
        forn(i, 0, data.size()) {
            auto& x = data[i];
            if (x.size() <= l) {
                l -= x.size();
                r -= x.size();
            } else if (r < x.size()) {
                fore(j, l, r) ans += (x[j] == k);
                return ans;
            } else if (l == 0) {
                ans += cnt[i][k];
                r -= x.size();
            } else {
                forn(j, l, x.size()) ans += (x[j] == k);
                l = 0;
                r -= x.size();
            }
        }
        return ans;
    }
} s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    s = SQRT((int)sqrt(n), a);
    int q;
    cin >> q;
    int block = (int)sqrt(q);
    int last = 0;
    s.cnt.assign((int)sqrt(n) + 2, vector<int>(N, 0));
    s.build();
    forn(i, 0, q) {
        if (i % block == 0) s.rebuild();
        int tp;
        cin >> tp;
        int l, r;
        cin >> l >> r;
        --l, --r;
        l += last, r += last;
        if (l >= n) l -= n;
        if (r >= n) r -= n;
        if (l > r) swap(l, r);
        if (tp == 1) {
            int val = s.erase(r);
            s.insert(l, val);
        } else {
            int k;
            cin >> k;
            k += last;
            if (k > n) k -= n;
            last = s.get(l, r, k);
            cout << last << '\n';
        }
    }
}