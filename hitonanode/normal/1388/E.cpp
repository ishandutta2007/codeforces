#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

// Convex Hull Trick
// Implementation Idea: <https://github.com/satanic0258/Cpp_snippet/blob/master/src/technique/ConvexHullTrick.cpp>
// #include <boost/multiprecision/cpp_int.hpp>
// using mpint = boost::multiprecision::cpp_int;
namespace CHT
{
using T_CHT = double;
static const T_CHT T_MIN = -1e30;
struct Line
{
    T_CHT a, b;                    // y = ax + b
    mutable std::pair<T_CHT, T_CHT> rp; // (numerator, denominator) `x` coordinate of the crossing point with next line
    Line(T_CHT a, T_CHT b) : a(a), b(b), rp(T_MIN, T_MIN) {}
    static std::pair<T_CHT, T_CHT> cross(const Line &ll, const Line &lr)
    {
        return std::make_pair(ll.b - lr.b, lr.a - ll.a); // `ll.a < lr.a` is assumed implicitly
    }
    bool operator<(const Line &r) const
    {
        if (b == T_MIN)
        {
            return r.rp.first == T_MIN ? true : a * r.rp.second < r.rp.first;
        }
        else if (r.b == T_MIN)
        {
            return rp.first == T_MIN ? false : !(r.a * rp.second < rp.first);
        }
        else
        {
            return a < r.a;
        }
    }
};
template <typename T_MP>
struct Lines : std::multiset<Line>
{
    bool flg_min; // true iff for minimization
    inline bool isNeedless(iterator itr) {
        if (size() == 1) return false;
        auto nxt = std::next(itr);
        if (itr == begin()) return itr->a == nxt->a and itr->b <= nxt->b;
        else
        {
            auto prv = std::prev(itr);
            if (nxt == end()) return itr->a == prv->a and itr->b <= prv->b;
            else return T_MP(prv->b - itr->b) * (nxt->a - itr->a) >= T_MP(itr->b - nxt->b) * (itr->a - prv->a);
        }
    }
    void add_line(T_CHT a, T_CHT b) {
        if (flg_min) a = -a, b = -b;
        auto itr = insert({a, b});
        if (isNeedless(itr)) erase(itr);
        else {
            while (std::next(itr) != end() and isNeedless(std::next(itr)))
            {
                erase(std::next(itr));
            }
            while (itr != begin() and isNeedless(std::prev(itr)))
            {
                erase(std::prev(itr));
            }
            if (std::next(itr) != end())
            {
                itr->rp = CHT::Line::cross(*itr, *std::next(itr));
            }
            if (itr != begin())
            {
                std::prev(itr)->rp = CHT::Line::cross(*std::prev(itr), *itr);
            }
        }
    }
    Lines(bool is_minimizer) : flg_min(is_minimizer) {}
    std::pair<T_CHT, T_CHT> get(T_CHT x) {
        auto itr = lower_bound({x, CHT::T_MIN});
        T_CHT retval = CHT::T_MIN, reta = CHT::T_MIN;
        if (itr != end()) {
            retval = itr->a * x + itr->b, reta = itr->a;
        }
        if (itr != begin())
        {
            T_CHT tmp = std::prev(itr)->a * x + std::prev(itr)->b;
            if (tmp >= retval) {
                retval = tmp, reta = std::max(reta, std::prev(itr)->a);
            }
        }
        return std::make_pair(flg_min ? -retval : retval, flg_min ? -reta : reta);
    }
};
} // namespace CHT

template <typename T_MP>
struct ConvexHullTrick
{
    using T_CHT = CHT::T_CHT;
    CHT::Lines<T_MP> lines;
    ConvexHullTrick(bool is_minimizer) : lines(is_minimizer) {}
    void add_line(T_CHT a, T_CHT b) { lines.add_line(a, b); } // Add y = ax + b
    std::pair<T_CHT, T_CHT> get(T_CHT x) { return lines.get(x); }
    void add_convex_parabola(T_CHT c, T_CHT a, T_CHT b) { add_line(c * a * (-2), c * a * a + b); } // Add y = c(x - a)^2 + b
    T_CHT parabola_lower_bound(T_CHT c, T_CHT x) { return lines.get(x).first + c * x * x; }
};

// Rational number + {infinity(1 / 0), -infiity(-1 / 0)} 
struct Rational {
    using Int = long long int; // __int128
    Int num, den;
    Rational(Int num = 0, Int den = 1) : num(num), den(den) { normalize(); }
    void normalize() { // reduction and making denominator nonnegative
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

double angle(int x1, int y1, int x2, int y2)
{
    int X = y2 - y1, Y = x1 - x2;
    return 1.0 * Y / X;
}
Rational Rangle(int x1, int y1, int x2, int y2)
{
    int X = y2 - y1, Y = x1 - x2;
    return Rational(Y, X);
}

int main()
{
    int N;
    cin >> N;
    vector<int> xl(N), xr(N), y(N);
    REP(i, N) cin >> xl[i] >> xr[i] >> y[i];
    ConvexHullTrick<double> chtmin(true), chtmax(false);
    REP(i, N)
    {
        chtmin.add_line(y[i], xl[i]);
        chtmax.add_line(y[i], xr[i]);
    }

    vector<pair<Rational, Rational>> ranges;
    REP(i, N) REP(j, i) if (y[i] != y[j])
    {
        auto t1 = Rangle(xl[i], y[i], xr[j], y[j]);
        auto t2 = Rangle(xr[i], y[i], xl[j], y[j]);
        ranges.emplace_back(minmax(t1, t2));
    }
    ranges.emplace_back(-1.2e12, -1.1e12);
    ranges.emplace_back(1.1e12, 1.2e12);
    sort(ranges.begin(), ranges.end());
    dbg(ranges);

    double ret = 1e30;
    Rational theta = -1e7;
    int ir = 0;

    auto eval = [&](double tangent_theta) -> bool {
        return chmin(ret, chtmax.get(tangent_theta).first - chtmin.get(tangent_theta).first);
    };

    while (ir < ranges.size())
    {
        if (theta > ranges[ir].first)
        {
            chmax(theta, ranges[ir].second);
            ir++;
            continue;
        }
        eval((long double)theta);
        theta = ranges[ir].first;
        eval((long double)theta);
        chmax(theta, ranges[ir].second);
        ir++;
    }
    cout << ret << '\n';
}