#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

struct ModInt {
    int x;
    ModInt(int x = 0) : x(x + (x < 0) * P - (x >= P) * P) {}
    ModInt operator+(ModInt o) { return x + o.x; }
    ModInt operator-(ModInt o) { return x - o.x; }
    ModInt operator*(ModInt o) { return 1LL * x * o.x % P; }
    ModInt operator/(ModInt b) { return *this * b.inv(); }
    ModInt inv() { return pow(P - 2); }
    ModInt pow(long long e) {
        if (!e) return 1;
        ModInt r = pow(e / 2);
        r = r * r;
        return e % 2 ? *this * r : r;
    }
    bool operator==(ModInt o) { return x == o.x; }
};

struct Arr {
    ModInt S;
    vector<pair<int, ModInt>> v;
    ModInt mul, add;

    Arr(int n) : v(1, {n, 1}), S(n), mul(1), add(0) { Dump(); }

    void Limit(int n) {
        int nn = v.back().first;
        if (nn == n) return;
        if (nn < n) {
            v.emplace_back(n, add * mul * (-1));
        } else {
            while (v.size()) {
                auto [r, x] = v.back();
                if (r <= n) break;
                if (v.size() == 1 || v[v.size() - 2].first < n) {
                    int delta = r - n;
                    S = S - (v.back().second * mul + add) * delta;
                    v.back().first = n;
                } else {
                    int delta = r - v[v.size() - 2].first;
                    S = S - (v.back().second * mul + add) * delta;
                    v.pop_back();
                }
            }
        }
        Dump();
    }
    void Negate() {
        S = S * (-1);
        mul = mul * (-1);
        add = add * (-1);
        Dump();
    }
    void Add(ModInt x) {
        S = S + x * v.back().first;
        add = add + x;
        Dump();
    }
    void Dump() {
        return;
        int j = 0;
        ModInt SS = 0;
        for (auto [e, x] : v) {
            x = x * mul + add;
            while (j < e) SS = SS + x, ++j;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int a0;
    cin >> a0;
    Arr A(a0);
    for (int i = 1; i < n; ++i) {
        int ai;
        cin >> ai;
        auto S = A.S;
        A.Limit(ai);
        A.Negate();
        A.Add(S);
    }
    cout << A.S.x << endl;
    return 0;
}