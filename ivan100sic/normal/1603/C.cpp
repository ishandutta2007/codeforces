// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<int m>
struct modint {
    unsigned x;

    modint() : x(0) {}
    modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

    modint operator+ (const modint& b) const {
        auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator- (const modint& b) const {
        auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator* (const modint& b) const {
        auto t = *this; t.x = ll(t.x) * b.x % m; return t;
    }

    modint operator/ (const modint& b) const {
        return *this * b.inv();
    }

    template<class T> modint operator^ (T n) const {
        modint t;
        if (n == 0) return t.x = 1, t;
        if (n == 1) return t.x = x, t;
        t = *this ^ (n >> 1); t *= t;
        return n & 1 ? *this * t : t;
    }

    modint& operator+= (const modint& b) { return *this = *this + b; }
    modint& operator-= (const modint& b) { return *this = *this - b; }
    modint& operator*= (const modint& b) { return *this = *this * b; }
    modint& operator/= (const modint& b) { return *this = *this / b; }
    modint& operator++ () { if (++x == m) x = 0; return *this; }
    modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
    modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
    modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
    bool operator== (const modint& other) const { return x == other.x; }
    bool operator!= (const modint& other) const { return x != other.x; }
    int operator() () const { return x; }
    template<class T> modint operator^= (T n) { return *this = *this ^ n; }
    modint inv() const { return *this ^ (m-2); }
};

const int mod = 998'244'353;
typedef modint<mod> mint;

int find_quot(int x, int cong) {
    int m = max(1, x / cong);
    while (1) {
        if (x / m + !!(x % m) <= cong) {
            return m;
        }
        m++;
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        R::reverse(a);

        mint ans = 0, pref = 0;
        vector<pair<int, int>> cc;

        for (int x : a) {
            if (cc.empty()) {
                cc.emplace_back(100000, 1);
            } else if (cc.back().first == 100000) {
                cc.back().second += 1;
            } else {
                cc.emplace_back(100000, 1);
            }

            vector<pair<int, int>> tmp;

            for (auto [cong, cnt] : cc) {
                int o = find_quot(x, cong);
                int newcong = x / o;
                pref += cnt * (o - 1ll);
                tmp.emplace_back(newcong, cnt);
            }

            R::sort(tmp);
            cc = {};
            for (auto [cong, cnt] : tmp) {
                if (cc.empty()) {
                    cc.emplace_back(cong, cnt);
                } else if (cc.back().first == cong) {
                    cc.back().second += cnt;
                } else {
                    cc.emplace_back(cong, cnt);
                }
            }

            ans += pref;
        }

        cout << ans() << '\n';
    }
    
}