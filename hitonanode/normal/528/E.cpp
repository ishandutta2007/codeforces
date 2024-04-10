// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
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
    T_P x, y;
    P() : x(0), y(0) {}
    P(T_P x, T_P y) : x(x), y(y) {}
    P(std::pair<T_P, T_P> p) : x(p.first), y(p.second) {}
    P operator+(const P &p) const noexcept { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const noexcept { return P(x - p.x, y - p.y); }
    P operator*(const P &p) const noexcept { return P(x * p.x - y * p.y, x * p.y + y * p.x); }
    P operator*(T_P d) const noexcept { return P(x * d, y * d); }
    bool operator<(const P &r) const noexcept { return x != r.x ? x < r.x : y < r.y; }
    bool operator==(const P &r) const noexcept { return x == r.x and y == r.y; }
    bool operator!=(const P &r) const noexcept { return !((*this) == r); }
    T_P dot(P p) const noexcept { return x * p.x + y * p.y; }
    T_P det(P p) const noexcept { return x * p.y - y * p.x; }
    T_P norm2() const noexcept { return x * x + y * y; }
    // rotate point/vector by rad
    friend std::istream &operator>>(std::istream &is, P &p) { T_P x, y; is >> x >> y; p = P(x, y); return is; }
    friend std::ostream &operator<<(std::ostream &os, const P &p) { os << '(' << p.x << ',' << p.y << ')'; return os; }
};

template <typename T_P>
int ccw(const P<T_P> &a, const P<T_P> &b, const P<T_P> &c) // a->b->c
{
    P<T_P> v1 = b - a;
    P<T_P> v2 = c - a;
    if (v1.det(v2) > 0) return 1; // 
    if (v1.det(v2) < 0) return -1; // 
    if (v1.dot(v2) < 0) return 2; // c-a-b
    if (v1.norm2() < v2.norm2()) return -2; // a-b-c
    return 0; // a-c-b
}

// Solve r1 + t1 * v1 == r2 + t2 * v2
template <typename T_P>
P<T_P> lines_crosspoint(P<T_P> r1, P<T_P> v1, P<T_P> r2, P<T_P> v2) {
    return r1 + v1 * (v2.det(r2 - r1) / v2.det(v1));
}

// Convex cut
// Cut the convex polygon g by line p1->p2 and return the leftward one
template <typename T_P>
std::vector<P<T_P>> convex_cut(const std::vector<P<T_P>>& g, P<T_P> p1, pint v) {
    std::vector<P<T_P>> ret;
    const P<T_P> p2(p1.x + v.first, p1.y + v.second);
    for (int i = 0; i < (int)g.size(); i++) {
        const P<T_P> now = g[i], nxt = g[(i + 1) % g.size()];
        if (ccw(p1, p2, now) != -1)
            ret.push_back(now);
        if ((ccw(p1, p2, now) == -1) xor (ccw(p1, p2, nxt) == -1)) {
            ret.push_back(lines_crosspoint(now, nxt - now, p1, p2 - p1));
        }
    }
    return ret;
}

template <typename T_P>
long double area_poly_ld(const std::vector<P<T_P>> &poly) {
    long double area = 0;
    for (size_t i = 0; i < poly.size(); i++) {
        size_t j = (i + 1 == poly.size() ? 0 : i + 1);
        area += (long double)poly[i].x * poly[j].y - (long double)poly[i].y * poly[j].x;
    }
    return area * 0.5;
}

using Float = double;
using Pt = P<Float>;

// 1-indexed BIT (i : [1, len])
template <typename T>
struct BIT : std::vector<T>
{
    BIT(int len = 0) : std::vector<T>(len + 1) {}
    void reset() { fill(this->begin(), this->end(), 0); }
    void add(int pos, T v) {
        while (pos > 0 and pos < (int)this->size()) (*this)[pos] += v, pos += pos & -pos;
    }
    T sum(int pos) const { // (0, pos]
        T res = 0;
        while (pos > 0) res += (*this)[pos], pos -= pos & -pos;
        return res;
    }
    friend std::ostream &operator<<(std::ostream &os, const BIT &bit) {
        T prv = 0;
        os << '[';
        for (int i = 1; i < (int)bit.size(); i++) {
            T now = bit.sum(i);
            os << now - prv << ",";
            prv = now;
        }
        os << ']';
        return os;
    }
};

int det(pint a, pint b) noexcept {
    return a.first * b.second - a.second * b.first;
}
int norm2(pint a) noexcept {
    return a.first * a.first + a.second * a.second;
}
Float cos2(pint a, pint b) noexcept {
    int num = a.first * b.first + a.second * b.second;
    return Float(1.0) * num * num / (norm2(a) * norm2(b)) * (num > 0 ? 1 : -1);
}

void ch(pint &x) {
    x.first = -x.first, x.second = -x.second;
}

// Solve r1 + t1 * v1 == r2 + t2 * v2 and return t1
template <typename T_P>
T_P lines_crosspoint_2(const P<T_P> &r1, const pint &v1, const P<T_P> &r2, const pint &v2)
{
    return (v2.first * (r2.y - r1.y) - v2.second * (r2.x - r1.x)) / det(v2, v1);
}

int main()
{
    int N;
    cin >> N;
    vector<Pt> P(N);
    vector<pint> V(N);

    REP(i, N) {
        Float a, b, c;
        cin >> a >> b >> c;
        if (a) P[i] = Pt(c / a, 0);
        else P[i] = Pt(0, c / b);
        V[i] = make_pair(-b, a);
    }

    constexpr Float Z = 1.0001e6;
    const vector<Pt> square { Pt(Z, Z), Pt(-Z, Z), Pt(-Z, -Z), Pt(Z, -Z) };
    const long double asq = area_poly_ld(square);

    long double ret = 0.0;

    lint dec = 1LL * N * (N - 1) * (N - 2) / 6 * 2;
    REP(i, N)
    {

        vector<pair<Float, int>> dj;
        dj.reserve(N - 1);
        vector<pair<Float, int>> a2j;
        a2j.reserve(N - 1);

        REP(j, N) if (j != i) {
            if (det(V[i], V[j]) < 0) {
                ch(V[j]);
            }
            const Float d = lines_crosspoint_2(P[i], V[i], P[j], V[j]);
            const Float a = cos2(V[i], V[j]);
            dj.emplace_back(d, j);
            a2j.emplace_back(a, j);
        }
        BIT<int> bit(N - 1);

        sort(a2j.begin(), a2j.end());
        vector<int> j2o(N, 1e9);
        REP(k, a2j.size()) j2o[a2j[k].second] = k + 1, bit.add(k + 1, 1);

        auto cvc = convex_cut(square, P[i], V[i]);
        ch(V[i]);
        auto cvcinv = convex_cut(square, P[i], V[i]);
        ch(V[i]);

        int nb_all = 0;
        int nb_all_inv = 0;
        sort(dj.begin(), dj.end());

        int cnt = dj.size();
        for (const auto [d_, j] : dj) {
            cnt--;
            bit.add(j2o[j], -1);
            int nb = bit.sum(j2o[j]);
            if (nb) {
                nb_all += nb;
                ret += area_poly_ld(convex_cut(cvcinv, P[j], V[j])) * nb;
            }
            int nbi = j2o[j] - 1 - nb;
            if (nbi) {
                nb_all_inv += nbi;
                ch(V[j]);
                ret += area_poly_ld(convex_cut(cvc, P[j], V[j])) * nbi;
                ch(V[j]);
            }
        }
        long double acvc = area_poly_ld(cvc);
        long double acvcinv = area_poly_ld(cvcinv);
        ret += acvc * nb_all + acvcinv * nb_all_inv;

        lint r = clamp(lint(ret / asq), 0LL, dec);
        dec -= r, ret -= asq * r;
    }
    ret -= asq * dec;
    cout << ret / (1.0l * N * (N - 1) * (N - 2) / 6) << '\n';
}