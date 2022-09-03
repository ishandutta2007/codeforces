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

using T = int;
struct RangeMinimumQuery
{
    int N;
    T defaultT = 1e9;
    int head;
    vector<T> x;
    T _get(int begin, int end, int pos, int l, int r) const
    {
        if (r <= begin or l >= end) return defaultT;
        if (l >= begin and r <= end) return x[pos];
        return min(_get(begin, end, 2 * pos + 1, l, (l + r) / 2), _get(begin, end, 2 * pos + 2, (l + r) / 2, r));
    }
    RangeMinimumQuery(int N, T defaultT) : N(N), defaultT(defaultT)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.assign(N_tmp*2, defaultT), head = N_tmp - 1;
    }
    void build(const vector<T> &vals)
    {
        copy(vals.begin(), vals.end(), x.begin() + head);
        for (int i = head - 1; i >= 0; i--)
        {
            x[i] = min(x[i * 2 + 1], x[i * 2 + 2]);
        }
    }
    RangeMinimumQuery(const vector<T> &vals, T defaultT) : N(vals.size()), defaultT(defaultT)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.assign(N_tmp*2, defaultT), head = N_tmp - 1;
        build(vals);
    }
    RangeMinimumQuery() : RangeMinimumQuery(0, T()) {}
    void update(int pos, T val)
    {
        pos += head, x[pos] = val;
        while (pos) pos = (pos - 1) / 2, x[pos] = min(x[pos * 2 + 1], x[pos * 2 + 2]);
    }
    T get(int begin, int end) const { return _get(begin, end, 0, 0, (int)x.size() / 2); }
    friend ostream &operator<<(ostream &os, const RangeMinimumQuery &s)
    {
        os << "[";
        for (int i = 0; i < s.N; i++) os << s.get(i, i + 1) << ",";
        os << "]";
        return os;
    }
};

int solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    vector<int> v { 1 };
    int ret = 0;
    int l = 1;
    while (l < N) {
        ret++;
        vector<int> vnxt;
        REP(_, v.size()) if (l < N) {
            vnxt.emplace_back(A[l]);
            while (l + 1 < N and A[l] < A[l + 1]) {
                l++;
                vnxt.emplace_back(A[l]);
            }
            l++;
        }
        v = vnxt;
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}