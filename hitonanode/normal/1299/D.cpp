#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

constexpr int Wmax = 5;

vector<bitset<Wmax>> gauss_jordan(int W, vector<bitset<Wmax>> mtr)
{
    int H = mtr.size(), c = 0;
    for (int h = 0; h < H; h++, c++)
    {
        if (c == W) break;
        int piv = -1;
        for (int j = h; j < H; j++) if (mtr[j][c]) {
                piv = j; break;
        }
        if (piv == -1) { h--; continue; }
        swap(mtr[piv], mtr[h]);
        for (int hh = 0; hh < H; hh++) {
            if (h != hh and mtr[hh][c]) mtr[hh] ^= mtr[h];
        }
    }
    return mtr;
}

int rank_gauss_jordan(int W, const vector<bitset<Wmax>> &mtr) // Rank of Gauss-Jordan eliminated matrix
{
    for (int h = (int)mtr.size() - 1; h >= 0; h--) {
        if (mtr[h]._Find_first() < W) return h + 1;
    }
    return 0;
}


template<typename T>
struct WeightedUnionFind
{
    std::vector<int> par, sz;
    std::vector<T> pot;
    WeightedUnionFind(int N = 0) : par(N), sz(N, 1), pot(N) {
        std::iota(par.begin(), par.end(), 0);
    }
    int find(int x) {
        if (par[x] != x) {
            int r = find(par[x]);
            pot[x] = pot[x] ^ pot[par[x]], par[x] = r;
        }
        return par[x];
    }
    bool unite(int s, int t, T rel_diff) {
        // Relate s and t by t = s + rel_diff
        // Return false iff contradiction happens.
        rel_diff = rel_diff ^ weight(s) ^ weight(t);
        if ((s = find(s)) == (t = find(t))) return rel_diff == 0;
        if (sz[s] < sz[t]) std::swap(s, t); 
        par[t] = s, sz[s] += sz[t], pot[t] = rel_diff;
        return true;
    }
    T weight(int x) { find(x); return pot[x]; }
    T diff(int s, int t) { return weight(t) ^ weight(s); }
    int count(int x) { return sz[find(x)]; }
    bool same(int s, int t) { return find(s) == find(t); }
};

template <int mod>
struct ModInt
{
    using lint = long long;
    int val;
    constexpr ModInt() : val(0) {}
    constexpr ModInt &_setval(lint v) { val = (v >= mod ? v - mod : v); return *this; }
    constexpr ModInt(lint v) { _setval(v % mod + mod); }
    explicit operator bool() const { return val != 0; }
    constexpr ModInt operator+(const ModInt &x) const { return ModInt()._setval((lint)val + x.val); }
    constexpr ModInt operator-(const ModInt &x) const { return ModInt()._setval((lint)val - x.val + mod); }
    constexpr ModInt operator*(const ModInt &x) const { return ModInt()._setval((lint)val * x.val % mod); }
    constexpr ModInt operator/(const ModInt &x) const { return ModInt()._setval((lint)val * x.inv() % mod); }
    constexpr ModInt operator-() const { return ModInt()._setval(mod - val); }
    constexpr ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    constexpr ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    constexpr ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    constexpr ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    friend constexpr ModInt operator+(lint a, const ModInt &x) { return ModInt()._setval(a % mod + x.val); }
    friend constexpr ModInt operator-(lint a, const ModInt &x) { return ModInt()._setval(a % mod - x.val + mod); }
    friend constexpr ModInt operator*(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.val % mod); }
    friend constexpr ModInt operator/(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.inv() % mod); }
    constexpr bool operator==(const ModInt &x) const { return val == x.val; }
    constexpr bool operator!=(const ModInt &x) const { return val != x.val; }
    bool operator<(const ModInt &x) const { return val < x.val; }  // To use std::map<ModInt, T>
    friend std::istream &operator>>(std::istream &is, ModInt &x) { lint t; is >> t; x = ModInt(t); return is; }
    friend std::ostream &operator<<(std::ostream &os, const ModInt &x) { os << x.val;  return os; }
    constexpr lint power(lint n) const {
        lint ans = 1, tmp = this->val;
        while (n) {
            if (n & 1) ans = ans * tmp % mod;
            tmp = tmp * tmp % mod;
            n /= 2;
        }
        return ans;
    }
    constexpr lint inv() const { return this->power(mod - 2); }
    constexpr ModInt operator^(lint n) const { return ModInt(this->power(n)); }
    constexpr ModInt &operator^=(lint n) { return *this = *this ^ n; }

    inline ModInt fac() const {
        static std::vector<ModInt> facs;
        int l0 = facs.size();
        if (l0 > this->val) return facs[this->val];

        facs.resize(this->val + 1);
        for (int i = l0; i <= this->val; i++) facs[i] = (i == 0 ? ModInt(1) : facs[i - 1] * ModInt(i));
        return facs[this->val];
    }

    ModInt doublefac() const {
        lint k = (this->val + 1) / 2;
        if (this->val & 1) return ModInt(k * 2).fac() / ModInt(2).power(k) / ModInt(k).fac();
        else return ModInt(k).fac() * ModInt(2).power(k);
    }

    ModInt nCr(const ModInt &r) const {
        if (this->val < r.val) return ModInt(0);
        return this->fac() / ((*this - r).fac() * r.fac());
    }
};

using mat = vector<bitset<Wmax>>;
using mint = ModInt<1000000007>;

int main()
{
    vector<mat> vec;
    vector<vector<int>> trans;
    REP(a, 1 << Wmax) REP(b, max(a, 1)) REP(c, max(b, 1)) REP(d, max(c, 1)) REP(e, max(d, 1)) {
        mat m{a, b, c, d, e};
        m = gauss_jordan(Wmax, m);
        if (std::count(vec.begin(), vec.end(), m)) {
            continue;
        }
        else vec.push_back(m);
    }
    for (auto m : vec) {
        int d = rank_gauss_jordan(Wmax, m);
        vector<int> tr(1 << Wmax, -1);
        if (d == Wmax) {
            trans.emplace_back(tr);
            continue;
        }
        REP(j, 1 << Wmax) {
            mat mm = m;
            mm[d] = j;
            mm = gauss_jordan(Wmax, mm);
            if (mm == m) {
                tr[j] = -1;
            }
            else {
                int nxt = find(ALL(vec), mm) - vec.begin();
                tr[j] = nxt;
            }
        }
        trans.emplace_back(tr);
    }

    int N, M;
    cin >> N >> M;
    WeightedUnionFind<int> uf(N);
    vector<tuple<int, int, int>> edges, epending;
    vector<pint> eroot;
    while (M--) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        if (a and b) edges.emplace_back(a, b, w);
        else eroot.emplace_back(a + b, w);
    }
    for (auto t : edges) {
        int a, b, w;
        tie(a, b, w) = t;
        if (uf.same(a, b)) {
            epending.push_back(t);
        }
        else uf.unite(a, b, w);
    }
    map<int, vector<int>> mb;
    map<int, vector<pint>> mr;
    for (auto t : epending)
    {
        int a, b, w;
        tie(a, b, w) = t;
        int r = uf.diff(a, b) ^ w;
        mb[uf.find(a)].emplace_back(r);
    }
    for (auto p : eroot) {
        mr[uf.find(p.first)].emplace_back(p);
    }


    vector<mint> dp(trans.size());
    dp[0] = 1;
    for (auto p : mr) {
        if (!p.second.size()) continue;
        int a = p.first;
        int radd = -1;
        if (p.second.size() == 2) {
            radd = uf.diff(p.second[0].first, p.second[1].first) ^ p.second[0].second ^ p.second[1].second;
        }

        vector<mint> dpnxt = dp;
        REP(i, dp.size()) if (dp[i]) {
            int S = i;
            for (auto j : mb[a]) {
                if (S >= 0) S = trans[S][j];
                else break;
            }
            if (S >= 0) {
                dpnxt[S] += dp[i] * (radd >= 0 ? 2 : 1);
                if (radd >= 0) {
                    S = trans[S][radd];
                    if (S >= 0) dpnxt[S] += dp[i];
                }
            }
        }
        dp = dpnxt;
    }
    cout << accumulate(ALL(dp), mint(0)) << endl;
}