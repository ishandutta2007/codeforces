#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios {
    fast_ios() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); };
} fast_ios_;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
//
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args>
void ndarray(vector<T>& vec, const V& val, int len, Args... args)
{
    vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); });
}
template <typename T>
bool chmax(T& m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T>
bool chmin(T& m, const T q) { return m > q ? (m = q, true) : false; }
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T>
vector<T> srtunq(vector<T> vec) { return sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()), vec; }
template <typename T>
istream& operator>>(istream& is, vector<T>& vec)
{
    return for_each(begin(vec), end(vec), [&](T& v) { is >> v; }), is;
}

// output
template <typename T, typename V>
ostream& dmpseq(ostream&, const T&, const string&, const string&, const string&);
#if __cplusplus >= 201703L
template <typename... T>
ostream& operator<<(ostream& os, const tuple<T...>& tpl)
{
    return apply([&os](auto&&... args) { ((os << args << ','), ...); }, tpl), os;
}
#endif
//
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '(' << p.first << ',' << p.second << ')'; }
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& x) { return dmpseq<vector<T>, T>(os, x, "[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& x) { return dmpseq<deque<T>, T>(os, x, "deq[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const set<T>& x) { return dmpseq<set<T>, T>(os, x, "{", ",", "}"); }
template <typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_set<T, TH>& x) { return dmpseq<unordered_set<T, TH>, T>(os, x, "{", ",", "}"); }
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& x) { return dmpseq<multiset<T>, T>(os, x, "{", ",", "}"); }
template <typename TK, typename T>
ostream& operator<<(ostream& os, const map<TK, T>& x) { return dmpseq<map<TK, T>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename TK, typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_map<TK, T, TH>& x) { return dmpseq<unordered_map<TK, T, TH>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename T, typename V>
ostream& dmpseq(ostream& os, const T& seq, const string& pre, const string& sp, const string& suf)
{
    return os << pre, for_each(begin(seq), end(seq), [&](V x) { os << x << sp; }), os << suf;
}
template <typename T>
void print(const vector<T>& x) { dmpseq<vector<T>, T>(cout, x, "", " ", "\n"); }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

// Rational number + {infinity(1 / 0), -infiity(-1 / 0)} 
struct Rational {
    using Int = long long int; // __int128
    Int num, den;
    static Int my_gcd(Int a, Int b) {
        // return __gcd(a, b);
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (a and b) {
            if (a > b) a %= b;
            else b %= a;
        }
        return a + b;
    }
    Rational(Int num = 0, Int den = 1) : num(num), den(den) { normalize(); }
    void normalize() { // reduction and making denominator nonnegative
        Int g = my_gcd(num, den); num /= g, den /= g;
        if (den < 0) num = -num, den = -den;
    }
    Rational operator+(const Rational &r) const { return Rational(num * r.den + den * r.num, den * r.den); }
    Rational operator-(const Rational &r) const { return Rational(num * r.den - den * r.num, den * r.den); }
    Rational operator*(const Rational &r) const { return Rational(num * r.num, den * r.den); }
    Rational operator/(const Rational &r) const { return Rational(num * r.den, den * r.num); }
    Rational &operator+=(const Rational &r) { return *this = *this + r; }
    Rational &operator-=(const Rational &r) { return *this = *this - r; }
    Rational &operator*=(const Rational &r) { return *this = *this * r; }
    Rational &operator/=(const Rational &r) { return *this = *this / r; }
    Rational operator-() const { return Rational(-num, den); }
    Rational abs() const { return Rational(num > 0 ? num : -num, den); }
    bool operator==(const Rational &r) const { return num == r.num and den == r.den; }
    bool operator!=(const Rational &r) const { return num != r.num or den != r.den; }
    bool operator<(const Rational &r) const {
        if (den == 0 and r.den == 0) return num < r.num;
        else if (den == 0) return num < 0;
        else if (r.den == 0) return r.num > 0;
        else return num * r.den < den * r.num;
    }
    bool operator<=(const Rational &r) const { return (*this == r) or (*this < r); }
    bool operator>(const Rational &r) const { return r < *this; }
    bool operator>=(const Rational &r) const { return (r == *this) or (r < *this); }
    explicit operator double() const { return (double)num / (double)den; }
    explicit operator long double() const { return (long double)num / (long double)den; }
    friend std::ostream &operator<<(std::ostream &os, const Rational &x) { os << x.num << '/' << x.den; return os; }
};

constexpr int INF = 1e9;
pair<Rational, Rational> solve(Rational xl, Rational xh, Rational rx, Rational vx)
{
    if (vx == 0) {
        if (xl < rx and rx < xh)
            return { -INF, INF };
        else
            return { INF, -INF };
    }
    if (xh < rx and vx > 0)
        return { INF, -INF };
    if (rx < xl and vx < 0)
        return { INF, -INF };
    return minmax((xl - rx) / vx, (xh - rx) / vx);
}
int main()
{
    int N;
    cin >> N;
    int xl, yl, xh, yh;
    cin >> xl >> yl >> xh >> yh;

    Rational lo = 0.0, hi = INF;
    REP(i, N)
    {
        int rx, ry, vx, vy;
        cin >> rx >> ry >> vx >> vy;
        auto [xs, xt] = solve(xl, xh, rx, vx);
        auto [ys, yt] = solve(yl, yh, ry, vy);
        chmax(lo, xs);
        chmax(lo, ys);
        chmin(hi, xt);
        chmin(hi, yt);
    }

    if (lo < hi) {
        cout << double(lo) << '\n';
    } else {
        puts("-1");
    }
}