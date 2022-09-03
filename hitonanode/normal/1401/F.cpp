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
    int N, Q;
    cin >> N >> Q;

    vector<int> L(1 << (N + 1), -1), R(1 << (N + 1), -1), INV(N + 1), PAR(1 << (N + 1));
    vector<lint> SUM(1 << (N + 1));

    REP(i, 1 << N)
    {
        cin >> SUM[(1 << N) + i];
    }

    IFOR(i, 1, 1 << N)
    {
        L[i] = 2 * i;
        R[i] = 2 * i + 1;
        PAR[L[i]] = PAR[R[i]] = i;
        SUM[i] = SUM[L[i]] + SUM[R[i]];
    }

    auto replace = [&](int i, int val) {
        int now = 1;
        IREP(d, N)
        {
            bool r = (i >> d) & 1;
            r ^= INV[N - 1 - d];
            now = r ? R[now] : L[now];
        }
        SUM[now] = val;
        REP(d, N)
        {
            now = PAR[now];
            SUM[now] = SUM[L[now]] + SUM[R[now]];
        }
    };

    auto swap = [&](int k) {
        INV[N - 1 - k] ^= 1;
    };

    auto reverse = [&](int k) {
        FOR(d, N - k, N) INV[d] ^= 1;
    };

    auto sum = [&](auto &&sum, int l, int r, int now, int begin, int end, int d) -> lint {
        if (begin >= r or end <= l) return 0;
        if (l <= begin and end <= r) return SUM[now];
        int cl = L[now], cr = R[now];
        if (INV[d])
        {
            int tmp = cl;
            cl = cr;
            cr = tmp;
        }
        lint ret1 = sum(sum, l, r, cl, begin, (begin + end) / 2, d + 1);
        lint ret2 = sum(sum, l, r, cr, (begin + end) / 2, end, d + 1);
        return ret1 + ret2;
    };

    while (Q--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int x, k;
            cin >> x >> k;
            replace(x - 1, k);
        }
        if (q == 2)
        {
            int k;
            cin >> k;
            reverse(k);
        }
        if (q == 3)
        {
            int k;
            cin >> k;
            swap(k);
        }
        if (q == 4)
        {
            int l, r;
            cin >> l >> r;
            cout << sum(sum, l - 1, r, 1, 0, 1 << N, 0) << '\n';
        }
        dbg(SUM);
        dbg(INV);
    }
}