#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os; }
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif

template <typename T_P>
struct P
{
    static T_P EPS;
    static void set_eps(T_P e)
    {
        EPS = e;
    }
    T_P x, y;
    P() : x(0), y(0) {}
    P(T_P x, T_P y) : x(x), y(y) {}
    P(std::pair<T_P, T_P> p) : x(p.first), y(p.second) {}
    static T_P add_w_error(T_P a, T_P b) noexcept { return (std::abs(a + b) < P::EPS * (std::abs(a) + std::abs(b))) ? 0 : a + b; }
    P operator+(const P &p) const noexcept { return P(add_w_error(x, p.x), add_w_error(y, p.y)); }
    P operator-(const P &p) const noexcept { return P(add_w_error(x, -p.x), add_w_error(y, -p.y)); }
    P operator*(const P &p) const noexcept { return P(add_w_error(x * p.x,  -y * p.y), add_w_error(x * p.y, y * p.x)); }
    P operator*(T_P d) const noexcept { return P(x * d, y * d); }
    P operator/(T_P d) const noexcept { return P(x / d, y / d); }
    P inv() const { return conj() / norm2(); }
    P operator/(const P &p) const { return (*this) * p.inv(); }
    bool operator<(const P &r) const noexcept { return x != r.x ? x < r.x : y < r.y; }
    bool operator==(const P &r) const noexcept { return add_w_error(x, -r.x) == 0 and add_w_error(y, -r.y) == 0; }
    bool operator!=(const P &r) const noexcept { return !((*this) == r); }
    T_P dot(P p) const noexcept { return add_w_error(x * p.x, y * p.y); }
    T_P det(P p) const noexcept { return add_w_error(x * p.y, -y * p.x); }
    T_P norm() const noexcept { return std::sqrt(x * x + y * y); }
    T_P norm2() const noexcept { return x * x + y * y; }
    T_P arg() const noexcept { return std::atan2(y, x); }
    // rotate point/vector by rad
    P rotate(T_P rad) noexcept { return P(add_w_error(x * std::cos(rad), -y * std::sin(rad)), add_w_error(x * std::sin(rad), y * std::cos(rad))); }
    P normalized() const { return (*this) / this->norm(); }
    P conj() const noexcept { return P(x, -y); }
    friend std::istream &operator>>(std::istream &is, P &p) { T_P x, y; is >> x >> y; p = P(x, y); return is; }
    friend std::ostream &operator<<(std::ostream &os, const P &p) { os << '(' << p.x << ',' << p.y << ')'; return os; }
};
template <>
double P<double>::EPS = 1e-9;
template <>
long double P<long double>::EPS = 1e-12;

using Pt = P<double>;

template <typename T_P>
T_P signed_area_of_polygon(const std::vector<P<T_P>>& poly)
{
    T_P area = 0;
    for (size_t i = 0; i < poly.size(); i++) {
        area += poly[i].det(poly[(i + 1) % poly.size()]);
    }
    return area * 0.5;
}

int main()
{
    vector<double> V(6);
    double pi = acos(-1.0);
    cin >> V;
    vector<Pt> vs;
    vs.emplace_back(0, 0);
    REP(i, 5) {
        Pt p = vs.back() + Pt(V[i], 0).rotate(pi / 3 * i);
        vs.emplace_back(p);
    }
    double area = signed_area_of_polygon(vs);
    cout << llround(area / (sqrt(3) / 4)) << '\n';
}