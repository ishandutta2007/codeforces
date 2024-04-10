#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template <typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template <typename V, typename T> void ndfill(V &x, const T &val) { x = val; }
template <typename V, typename T> void ndfill(vector<V> &vec, const T &val) { for (auto &v : vec) ndfill(v, val); }
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
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

int main()
{
    int N, M, K;
    string S, T;
    cin >> N >> M >> K >> S >> T;
    vector<int> io(K);
    iota(io.begin(), io.end(), 0);
    vector AP(N + 1, io);
    vector<int> A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i], A[i]--, B[i]--;

    vector scn(1 << K, N + 1);
    vector tcn(1 << K, -1);

    IREP(i, N)
    {
        swap(AP[i][A[i]], AP[i][B[i]]);
        REP(j, K) AP[i][j] = AP[i + 1][AP[i][j]];

        if (i + M <= N)
        {
            int tp = 0;
            REP(d, K) if (T[d] == '1') tp += 1 << AP[i + M][d];
            chmax(tcn[tp], i + M);
        }
        int sp = 0;
        REP(d, K) if (S[d] == '1') sp += 1 << AP[i][d];
        chmin(scn[sp], i);
    }

    vector D(K + 1, vector<int>(1 << K, N + 1));
    REP(S, 1 << K)
    {
        chmin(D[0][S], scn[S]);
    }
    REP(d, K) REP(S, 1 << K)
    {
        REP(e, K)
        {
            chmin(D[d + 1][S ^ (1 << e)], D[d][S]);
        }
    }
    dbg(D[0]);
    dbg(D[1]);
    dbg(D[2]);
    dbg(D[3]);
    dbg(tcn);
    int ret = 1e9, retl = -1, retr = -1;
    REP(d, K + 1) REP(S, 1 << K)
    {
        if (D[d][S] + M <= tcn[S] and chmin(ret, d))
        {
            retl = D[d][S], retr = tcn[S];
        }
    }
    cout << K - ret << '\n' << retl + 1 << ' ' << retr << '\n';
}