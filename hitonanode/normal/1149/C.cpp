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

template <typename T>
struct SegTree
{
    int N;
    int head;
    vector<T> x;
    T defaultT;
    using func = function<T(const T&, const T&)>;
    func merger;
    T _get(int begin, int end, int pos, int l, int r) const
    {
        if (r <= begin or l >= end) return defaultT;
        if (l >= begin and r <= end) return x[pos];
        return merger(_get(begin, end, 2 * pos + 1, l, (l + r) / 2), _get(begin, end, 2 * pos + 2, (l + r) / 2, r));
    }
    SegTree(int N, T defaultT, func merger) : N(N), defaultT(defaultT), merger(merger)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x = vector<T>(N_tmp*2, defaultT), head = N_tmp - 1;
    }
    SegTree() : SegTree(0, T(), [](T, T) { return T(); }) {}
    void build(const vector<T> &vals) { REP(i, vals.size()) x[head + i] = vals[i]; IREP(i, head) x[i] = merger(x[i * 2 + 1], x[i * 2 + 2]); }
    void update(int pos, T val) { pos += head, x[pos] = val; while (pos) pos = (pos - 1) / 2, x[pos] = merger(x[pos*2+1], x[pos*2+2]); }
    T get(int begin, int end) const{ return _get(begin, end, 0, 0, (int)x.size() / 2); }
};
// template<typename T> ostream &operator<<(ostream &os, const SegTree<T> &s) { os << "["; REP(i, s.N) os << s.get(i, i + 1) << ","; os << "]"; return os;}

struct Mn{
    int hi, lo2, hilo2, lo2hi, df, c;
    Mn(): hi(0), lo2(0), hilo2(0), lo2hi(0), df(0), c(0) {}
    Mn(int sgn)
    {
        if (sgn > 0) hi = 1, lo2 = 0, hilo2 = 0, lo2hi = 1, df = 1, c = 1;
        else hi = 0, lo2 = 2, hilo2 = 2, lo2hi = 0, df = -1, c = 0;
    }
};
// ostream &operator<<(ostream &os, const Mn &mn) { os << "[" << mn.hi << " " << mn.lo << " " << mn.df << " " << mn.c <<  "]"; return os;}

int main()
{
    int N, Q;
    cin >> N >> Q;
    SegTree<Mn> st((N - 1) * 2, Mn(), [](const Mn &L, const Mn &R) {
        Mn ret;
        ret.hi = max(L.hi, L.df + R.hi);
        ret.lo2 = max(L.lo2, -L.df * 2 + R.lo2);
        ret.hilo2 = max(max(L.hilo2, -L.df + R.hilo2), L.hi - L.df * 2 + R.lo2);
        ret.lo2hi = max(max(L.lo2hi, -L.df + R.lo2hi), L.lo2 + L.df + R.hi);
        ret.df = L.df + R.df;
        ret.c = max(max(L.c, R.c), max(L.hi - L.df + R.lo2hi, L.hilo2 + L.df + R.hi));
        return ret;
    });
    string s;
    cin >> s;
    vector<Mn> vec(s.length());
    REP(i, s.length()) vec[i] = Mn(s[i] == '(');
    st.build(vec);

    Mn v = st.get(0, s.length());
    printf("%d\n", v.c);

    REP(_, Q)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        swap(vec[x], vec[y]);
        st.update(x, vec[x]);
        st.update(y, vec[y]);
        Mn v = st.get(0, s.length());
        printf("%d\n", v.c);
    }
}