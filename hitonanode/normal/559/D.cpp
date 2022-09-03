#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
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
    // static T_P add_w_error(T_P a, T_P b) noexcept { return (std::abs(a + b) < P::EPS * (std::abs(a) + std::abs(b))) ? 0 : a + b; }
    static T_P add_w_error(T_P a, T_P b) noexcept { return a + b; }
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
lint P<lint>::EPS = 0;

template <typename T_P>
T_P signed_area2_of_polygon(const std::vector<P<T_P>> &poly)
{
    T_P area = 0;
    for (size_t i = 0; i < poly.size(); i++) {
        area += poly[i].det(poly[(i + 1) % poly.size()]);
    }
    return area;
}
using Pt = P<lint>;

int main()
{
    int N;
    cin >> N;
    vector<Pt> ps(N);
    vector<lint> dets;
    vector<lint> gs;
    cin >> ps;
    lint S2 = signed_area2_of_polygon(ps);
    if (S2 < 0) {
        reverse(ps.begin(), ps.end());
        S2 = signed_area2_of_polygon(ps);
    }

    S2 += 2;

    REP(i, N) ps.emplace_back(ps[i]);

    REP(i, N) {
        dets.emplace_back(ps[i].det(ps[i + 1]));
        Pt dr = ps[(i + 1) % N] - ps[i];
        lint g = __gcd(abs(dr.x), abs(dr.y));
        gs.emplace_back(g);
        S2 -= g;
    }
    REP(i, N) dets.emplace_back(dets[i]), gs.emplace_back(gs[i]);

    const lint nin = S2 / 2;

    vector<lint> adets(N * 2 + 1), ags(N * 2 + 1);
    REP(i, N * 2) {
        adets[i + 1] = adets[i] + dets[i];
        ags[i + 1] = ags[i] + gs[i];
    }
    auto calc = [&](int l, int r) -> lint {
        Pt dr = ps[l] - ps[r];
        lint n = (adets[r] - adets[l] + ps[r].det(ps[l]) - (ags[r] - ags[l]) + __gcd(abs(dr.x), abs(dr.y))) / 2;
        return n;
    };

    constexpr int W = 100;
    vector<long double> cnt(W);
    FOR(w, 2, min(N - 1, W)) {
        REP(i, N) {
            cnt[w] += calc(i, i + w);
        }
    }

    vector<long double> pow2i(N + 10, 1);
    FOR(i, 1, pow2i.size()) pow2i[i] = pow2i[i - 1] * 0.5;
    long double allp = (1 + N + 1.0l * N * (N - 1) / 2) * pow2i[N];
    allp = 1.0 - allp;
    const long double allpinv = 1.0 / allp;

    long double ret = nin;
    FOR(w, 2, min(N - 1, W)) {
        ret -= pow2i[w + 1] * cnt[w] * (1.0 - pow2i[N - w - 1]) * allpinv;
    }
    cout << ret << '\n';
}