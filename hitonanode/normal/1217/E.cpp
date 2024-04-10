#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
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
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

constexpr int INF = 1e9 + 10;
struct D
{
    vector<pint> d;
    D(int x = 0) : d(10, pint(INF, INF))
    {
        int a = x;
        REP(i, 10)
        {
            if (a % 10) d[i].first = x;
            a /= 10;
        }
    }
};

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
        x.assign(N_tmp*2, defaultT), head = N_tmp - 1;
    }
    SegTree(const vector<T> &vals, T defaultT, func merger) : N(vals.size()), defaultT(defaultT), merger(merger)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.assign(N_tmp*2, defaultT), head = N_tmp - 1;
        copy(vals.begin(), vals.end(), x.begin() + head);
        IREP(i, head) x[i] = merger(x[i * 2 + 1], x[i * 2 + 2]);
    }
    SegTree() : SegTree(0, T(), [](T, T) { return T(); }) {}
    void build(const vector<T> &vals) { copy(vals.begin(), vals.end(), x.begin() + head); IREP(i, head) x[i] = merger(x[i * 2 + 1], x[i * 2 + 2]); }
    void update(int pos, T val) { pos += head, x[pos] = val; while (pos) pos = (pos - 1) / 2, x[pos] = merger(x[pos*2+1], x[pos*2+2]); }
    T get(int begin, int end) const { return _get(begin, end, 0, 0, (int)x.size() / 2); }
    friend ostream &operator<<(ostream &os, const SegTree<T> &s) { os << "["; REP(i, s.N) os << s.get(i, i + 1) << ","; os << "]"; return os; }
};

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<D> v(N);
    REP(i, N)
    {
        int t;
        cin >> t;
        v[i] = t;
    }
    SegTree<D> st(v, D(), [](const D &l, const D &r) {
        D ret;
        REP(i, 10)
        {
            ret.d[i].first = min(l.d[i].first, r.d[i].first);
            ret.d[i].second = min(max(l.d[i].first, r.d[i].first), min(l.d[i].second, r.d[i].second));
        }
        return ret;
    });
    REP(_, Q)
    {
        int s;
        cin >> s;
        if (s == 1)
        {
            int i, x;
            cin >> i >> x;
            st.update(i - 1, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            D w = st.get(l - 1, r);
            int ret = INF * 2;
            REP(i, 10)
            {
                if (w.d[i].second < INF)
                {
                    mmin(ret, w.d[i].first + w.d[i].second);
                }
            }
            printf("%d\n", (ret < INF * 2 ? ret : -1));
        }
    }
}