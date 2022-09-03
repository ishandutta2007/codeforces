#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
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
    P operator+(const P &p) const noexcept { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const noexcept { return P(x - p.x, y - p.y); }
    P operator*(const P &p) const noexcept { return P(x * p.x - y * p.y, x * p.y + y * p.x); }
    P operator*(T_P d) const noexcept { return P(x * d, y * d); }
    P operator/(T_P d) const noexcept { return P(x / d, y / d); }
    P inv() const { return conj() / norm2(); }
    P operator/(const P &p) const { return (*this) * p.inv(); }
    bool operator<(const P &r) const noexcept { return x != r.x ? x < r.x : y < r.y; }
    bool operator==(const P &r) const noexcept { return x == r.x and y  == r.y; }
    bool operator!=(const P &r) const noexcept { return !((*this) == r); }
    T_P dot(P p) const noexcept { return x * p.x + y * p.y; }
    T_P det(P p) const noexcept { return x * p.y - y * p.x; }
    T_P norm() const noexcept { return std::sqrt(x * x + y * y); }
    T_P norm2() const noexcept { return x * x + y * y; }
    T_P arg() const noexcept { return std::atan2(y, x); }
    // rotate point/vector by rad
    P rotate(T_P rad) noexcept { return P(x * std::cos(rad) - y * std::sin(rad), x * std::sin(rad) + y * std::cos(rad)); }
    P normalized() const { return (*this) / this->norm(); }
    P conj() const noexcept { return P(x, -y); }
    friend std::istream &operator>>(std::istream &is, P &p) { T_P x, y; is >> x >> y; p = P(x, y); return is; }
    friend std::ostream &operator<<(std::ostream &os, const P &p) { os << '(' << p.x << ',' << p.y << ')'; return os; }
};
template <>
double P<double>::EPS = 1e-9;
template <>
long double P<long double>::EPS = 1e-12;


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


template <typename T1, typename T2>
long long subproblem(std::vector<std::pair<std::pair<T1, T2>, int>> vs, const vector<T2> &dict) {
    sort(ALL(vs));

    long long ret = 0;
    BIT<int> bit(dict.size());
    for (auto [p, i] : vs) {
        auto rt = p.second;
        int r = std::lower_bound(dict.begin(), dict.end(), rt) - dict.begin();
        if (i) {
            ret += bit.sum(dict.size()) - bit.sum(r + 1);
        }
        bit.add(r + 1, 1);
    }
    return ret;
}

struct rand_int_
{
    using lint = long long;
    mt19937 mt;
    rand_int_() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    lint operator()(lint x) { return this->operator()(0, x); } // [0, x)
    lint operator()(lint l, lint r) {
        uniform_int_distribution<lint> d(l, r - 1);
        return d(mt);
    }
} rnd;

const Float PI = acosl(-1.0l);
const Float PI2 = PI * 2;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    lint N, K;
    cin >> N >> K;

    vector<Pt> ps(N);
    cin >> ps;
    REP(i, N) ps[i] = ps[i].rotate(0.17310);
    REP(i, N) {
        ps[i].x += 1.0e-8 * rnd(10000) / 10000;
        ps[i].y += 1.0e-8 * rnd(10000) / 10000;
    }

    vector<Float> RR(N), args(N);
    REP(i, N) {
        RR[i] = ps[i].norm(), args[i] = ps[i].arg();
    }

    Float lo = 0.0000001, hi = 1.5e4;
    REP(_, 30) {

        const Float c = sqrt(lo * hi);
        lint cnt = 0;
        vector<pair<Float, pair<Float, int>>> query;
        vector<pair<pair<Float, Float>, int>> vsub;

        vector<Float> dict;
        REP(i, N) {
            if (RR[i] <= c) continue;

            Float t = acos(c / RR[i]);
            Float L = args[i] - t, R = args[i] + t;
            FOR(rot, -1, 2) {
                Float ROT = rot * PI2;
                vsub.emplace_back(make_pair(L + ROT, R + ROT), (rot == 0));
                query.emplace_back(L + ROT, make_pair(R + ROT, +1));
                query.emplace_back(R + ROT, make_pair(R + ROT, -2 + (rot == 0)));
                dict.emplace_back(R + ROT);
            }
        }

        dict = srtunq(dict);

        BIT<int> bit2(dict.size());
        sort(ALL(vsub));
        int su = 0;
        for (auto [p, i] : vsub) {
            auto [l, rf] = p;
            int r = lower_bound(ALL(dict), rf) - dict.begin();
            if (i) {
                cnt -= su - bit2.sum(r + 1);
            }
            bit2.add(r + 1, 1), su++;
        }

        BIT<int> bit(dict.size());
        sort(ALL(query));
        su = 0;
        for (auto [rad, pp] : query) {
            int ar = lower_bound(ALL(dict), pp.first) - dict.begin();
            int i = pp.second;
            if (i > 0) {
                bit.add(ar + 1, 1), su++;
            } else {
                bit.add(ar + 1, -1), su--;
                if (i == -1) {
                    cnt += su - bit.sum(ar);
                }
            }
        }
        (cnt > N * (N - 1) / 2 - K ? lo : hi) = c;
    }
    cout << lo << '\n';
}