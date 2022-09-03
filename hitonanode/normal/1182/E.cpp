#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FI first
#define SE second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////

constexpr lint MOD = 1000000007;

template<typename T>
struct Matrix
{
    int H, W;
    vector<T> elem;
    typename vector<T>::iterator operator[](int i) { return elem.begin() + i * W; }
    inline T &at(int i, int j) { return elem[i * W + j]; }
    inline T get(int i, int j) const { return elem[i * W + j]; }
    operator vector<vector<T>>() const { vector<vector<T>> ret(H, vector<T>(W)); REP(i, H) REP(j, W) ret[i][j] = at(i, j); return ret; }
    
    Matrix(int H, int W) : H(H), W(W), elem(H * W) {}
    Matrix(const vector<vector<T>> &d) { H = d.size(), W = d[0].size(); elem.resize(H * W); REP(i, H) REP(j, W) elem.at(i, j) = d[i][j]; }

    static Matrix Identity(int N) { Matrix ret(N, N); REP(i, N) ret.at(i, i) = (T)1; return ret; }

    Matrix operator-() const { Matrix ret(H, W); REP(i, H * W) ret.elem[i] = -elem[i]; return ret; }
    Matrix operator+(const Matrix &r) const { Matrix ret(H, W); REP(i, H * W) ret.elem[i] = elem[i] + r.elem[i]; return ret; }
    Matrix operator-(const Matrix &r) const { Matrix ret(H, W); REP(i, H * W) ret.elem[i] = elem[i] - r.elem[i]; return ret; }
    Matrix operator*(const Matrix &r) const {
        Matrix ret(H, r.W);
        REP(i, H) REP(k, W) REP(j, r.W) ret.at(i, j) += this->get(i, k) * r.get(k, j);
        return ret;
    }
    Matrix &operator+=(const Matrix &r) { return *this = *this + r; }
    Matrix &operator-=(const Matrix &r) { return *this = *this - r; }
    Matrix &operator*=(const Matrix &r) { return *this = *this * r; }
    Matrix pow(int64_t n) const {
        Matrix ret = Identity(H);
        if (n == 0) return ret;
        IREP(i, 64 - __builtin_clzll(n))
        {
            ret *= ret;
            if ((n >> i) & 1) ret *= (*this);
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const Matrix &x) { os << x.elem;  return os; }
    friend istream &operator>>(istream &is, Matrix &x) { for (auto &v : x.elem) is >> v; return is; }
};

template <int mod>
struct ModInt
{
    using lint = long long;
    int val;
    ModInt() : val(0) {}
    void _setval(lint v) { v = (v % mod) + mod; val = v >= mod ? v - mod : v; }
    ModInt(lint v) { _setval(v); }
    operator int() const { return val; }
    ModInt operator+(const ModInt &x) const { return ModInt((lint)val + x.val); }
    ModInt operator-(const ModInt &x) const { return ModInt((lint)val - x.val); }
    ModInt operator*(const ModInt &x) const { return ModInt((lint)val * x.val); }
    ModInt operator/(const ModInt &x) const { return ModInt((lint)val * x.inv()); }
    ModInt operator-() const { return ModInt(-val); }
    ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    bool operator==(const ModInt &x) { return val == x.val; }
    bool operator!=(const ModInt &x) { return val != x.val; }
    friend ostream &operator<<(ostream &os, const ModInt &x) { os << x.val;  return os; }

    inline lint power(lint n) const {
        lint ans = 1, tmp = this->val;
        while (n) {
            if (n & 1) ans = ans * tmp % mod;
            tmp = tmp * tmp % mod;
            n /= 2;
        }
        return ans;
    }
    inline lint inv() const { return this->power(mod - 2); }
    
    inline ModInt fac() const {
        static vector<ModInt> facs;
        int l0 = facs.size();
        if (l0 > this->val) return facs[this->val];

        facs.resize(this->val + 1);
        for (int i = l0; i <= this->val; i++) facs[i] = (i == 0 ? 1 : facs[i - 1] * i);
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
using mint = ModInt<MOD - 1>;
using mat = Matrix<mint>;

lint power(lint x, lint n, lint MOD)
{
    lint ans = 1;
    while (n>0)
    {
        if (n & 1) (ans *= x) %= MOD;
        (x *= x) %= MOD;
       n >>= 1;
    }
   return ans;
}

// Solve ax+by=gcd(a, b)
lint extgcd(lint a, lint b, lint &x, lint &y)
{
    lint d = a;
    if (b != 0) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    else x = 1, y = 0;
    return d;
}
// Calc a^(-1) (MOD m)
lint mod_inverse(lint a, lint m)
{
    lint x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
int main()
{
    lint N, f1, f2, f3, c;
    cin >> N >> f1 >> f2 >> f3 >> c;

    mat trans(9, 9);
    REP(i, 6) trans[i][i + 3] = 1;
    REP(i, 3) REP(j, 3) trans[6 + i][i + 3 * j] = 1;
    mat po = trans.pow(N - 3);

    mint a1 = po[6][0] + po[6][4] + po[6][8];
    mint a2 = po[7][0] + po[7][4] + po[7][8];
    mint a3 = po[8][0] + po[8][4] + po[8][8];

    lint ret = power(f1 * c % MOD, (lint)a1, MOD)
               * power(f2 * c % MOD * c % MOD, (lint)a2, MOD) % MOD
               * power(f3 * c % MOD * c % MOD * c % MOD, (lint)a3, MOD) % MOD
               * mod_inverse(power(c, N, MOD), MOD) % MOD;
    cout << ret << endl;
}