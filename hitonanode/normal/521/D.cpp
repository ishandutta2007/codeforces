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

// Rational number + {infinity(1 / 0), -infiity(-1 / 0)} 
struct Rational {
    // using Int = long long int; // __int128
    using Int = __int128;
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
    // friend std::ostream &operator<<(std::ostream &os, const Rational &x) { os << x.num << '/' << x.den; return os; }
};

int main()
{
    int K, N, M;
    cin >> K >> N >> M;
    vector<lint> A(K);
    cin >> A;
    vector<int> upd_id(K, -1), upd_val(K, -1);
    vector<vector<pint>> add(K);
    vector<pair<Rational, int>> mul;

    vector<int> id2type(N + 1);
    FOR(id_, 1, N + 1)
    {
        int t, i, b;
        cin >> t >> i >> b;
        i--;
        id2type[id_] = t;
        if (t == 1) {
            if (chmax(upd_val[i], b)) upd_id[i] = id_;
        } else if (t == 2) {
            add[i].emplace_back(b, id_);
        } else {
            mul.emplace_back(b, id_);
        }
    }
    sort(mul.rbegin(), mul.rend());

    REP(k, K) if (upd_val[k] > A[k]) add[k].emplace_back(upd_val[k] - A[k], upd_id[k]);

    vector<int> nb_add(K);

    REP(k, K) {
        sort(add[k].rbegin(), add[k].rend());
        lint prvsum = A[k];
        for (auto [adv, i] : add[k]) {
            mul.emplace_back(Rational(adv + prvsum, prvsum), i);
            prvsum += adv;
        }
    }
    sort(mul.rbegin(), mul.rend());

    int L = min<int>(M, mul.size());
    cout << L << '\n';
    vector<int> ret;
    FOR(d, 1, 4) REP(i, L) {
        int id_ = mul[i].second;
        if (id2type[id_] == d) ret.emplace_back(id_);
    }
    for (auto x : ret) cout << x << ' ';
    cout << '\n';
}