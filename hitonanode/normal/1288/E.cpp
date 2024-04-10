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
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
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
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#else
#define dbg(x) (x)
#endif

// Count elements in [A_begin, ..., A_{end-1}] which satisfy A_i < query
// Complexity: O(N log N) for initialization, O(log^2 N) for each query
// Verified: cntLess <https://codeforces.com/contest/1288/submission/68865506>
template <typename T> struct CountLessThan {
    int N;
    vector<vector<T>> x;
    CountLessThan() = default;
    CountLessThan(const vector<T> &vec) : N(vec.size()) {
        x.resize(N * 2);
        for (int i = 0; i < N; i++) x[N + i] = {vec[i]};
        for (int i = N - 1; i; i--) std::merge(x[i * 2].begin(), x[i * 2].end(), x[i * 2 + 1].begin(), x[i * 2 + 1].end(), std::back_inserter(x[i]));
    }
    int cntLess(int l, int r, T query) const {
        l += N, r += N;
        int ret = 0;
        while (l < r) {
            if (l & 1) ret += std::lower_bound(x[l].begin(), x[l].end(), query) - x[l].begin(), l++;
            if (r & 1) r--, ret += std::lower_bound(x[r].begin(), x[r].end(), query) - x[r].begin();
            l >>= 1, r >>= 1;
        }
        return ret;
    }
    int cntLesseq(int l, int r, T query) const {
        l += N, r += N;
        int ret = 0;
        while (l < r) {
            if (l & 1) ret += std::upper_bound(x[l].begin(), x[l].end(), query) - x[l].begin(), l++;
            if (r & 1) r--, ret += std::upper_bound(x[r].begin(), x[r].end(), query) - x[r].begin();
            l >>= 1, r >>= 1;
        }
        return ret;
    }
    int cntMore(int begin, int end, T query) const {
        int tot = max(0, min(end, N) - max(begin, 0));
        return tot - cntLesseq(begin, end, query);
    }
    int cntMoreeq(int begin, int end, T query) const {
        int tot = max(0, min(end, N) - max(begin, 0));
        return tot - cntLess(begin, end, query);
    }

    friend ostream &operator<<(ostream &os, const CountLessThan &clt) {
        os << '[';
        for (int i = 0; i < clt.N; i++) os << clt.x[clt.N + i][0] << ',';
        return os << ']';
    }
};

// 1-indexed BIT (i : [1, len])
template <typename T> struct BIT : std::vector<T> {
    BIT(int len = 0) : std::vector<T>(len + 1, 0) {}
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

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    cin >> A;
    vector<int> last(N + 1, -1);
    vector<int> prv(M, -1);
    REP(t, M) {
        prv[t] = last[A[t]];
        last[A[t]] = t;
    }

    CountLessThan st(prv);
    vector<int> lo(N + 1), hi(N + 1);
    FOR(i, 1, N + 1) lo[i] = hi[i] = i - 1;

    BIT<int> bit(N);
    REP(i, M) {
        lo[A[i]] = 0;
        if (prv[i] == -1) {
            chmax(hi[A[i]], A[i] - 1 + bit.sum(N) - bit.sum(A[i]));
            bit.add(A[i], 1);
        } else
            chmax(hi[A[i]], st.cntLess(prv[i] + 1, i, prv[i]));
    }
    FOR(n, 1, N + 1) {
        if (last[n] == -1) {
            hi[n] = n - 1 + bit.sum(N) - bit.sum(n);
        } else
            chmax(hi[n], st.cntLess(last[n] + 1, M, last[n]));
    }
    FOR(i, 1, N + 1) printf("%d %d\n", lo[i] + 1, hi[i] + 1);
}