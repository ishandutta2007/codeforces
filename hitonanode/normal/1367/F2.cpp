#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
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

// Binary lifting / `Doubling`
// Complexity: O(NlogN) precalculation / O(logN) per query
// <https://atcoder.jp/contests/arc060/submissions/7039451>
struct BinaryLifting
{
    int N, INVALID, lgD;
    std::vector<std::vector<int>> mat;
    BinaryLifting() : N(0), lgD(0) {}
    BinaryLifting(const std::vector<int> &vec_nxt, int INVALID = -1, int lgd = 0) : N(vec_nxt.size()), INVALID(INVALID), lgD(lgd)
    {
        while ((1LL << lgD) < N) lgD++;
        mat.assign(lgD, std::vector<int>(N, INVALID));
        mat[0] = vec_nxt;
        for (int i = 0; i < N; i++) if (mat[0][i] < 0 or mat[0][i] >= N) mat[0][i] = INVALID;
        for (int d = 0; d < lgD - 1; d++) {
            for (int i = 0; i < N; i++) if (mat[d][i] != INVALID) mat[d + 1][i] = mat[d][mat[d][i]];
        }
    }
    int kth_next(int now, long long k)
    {
        if (k == 0) return now;
        if (k >= (1LL << lgD)) exit(8);
        for (int d = 0; k and now != INVALID; d++, k >>= 1) if (k & 1) now = mat[d][now];
        return now;
    }

    // Distance from l to [r, \infty)
    // Requirement: mat[0][i] > i for all i (monotone increasing)
    int distance(int l, int r)
    {
        if (l >= r) return 0;
        int ret = 0;
        for (int d = lgD - 1; d >= 0; d--) {
            if (mat[d][l] < r and mat[d][l] != INVALID) ret += 1 << d, l = mat[d][l];
        }
        if (mat[0][l] == INVALID or mat[0][l] >= r) return ret + 1;
        else return -1; // Unable to reach
    }
};

int solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;

    map<int, vector<int>> a2i;
    REP(i, N) a2i[A[i]].emplace_back(i);

    int ret = 0;

    vector<int> nxt(N, N);
    REP(i, N)
    {
        vector<int> &v = a2i.at(A[i]);
        if (v.back() != i)
        {
            nxt[i] = *upper_bound(v.begin(), v.end(), i);
        }
        else
        {
            auto itr = a2i.upper_bound(A[i]);
            if (itr != a2i.end())
            {
                vector<int> &w = itr->second;
                if (w[0] > i) nxt[i] = w[0];
            }
        }
    }
    BinaryLifting bl(nxt, N, 18);
    vector<int> as = A;
    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
    REP(i, as.size() - 1)
    {
        vector<int> &v1 = a2i.at(as[i]);
        vector<int> &v2 = a2i.at(as[i + 1]);
        REP(n, v1.size())
        {
            chmax<int>(ret, n + 1 + (v2.end() - upper_bound(v2.begin(), v2.end(), v1[n])));
        }
    }
    REP(i, N)
    {
        int d = bl.distance(i, N);
        int j = bl.kth_next(i, d - 1);
        auto itr = upper_bound(as.begin(), as.end(), A[j]);
        int a1 = 0, a2 = 0;
        if (itr != as.end())
        {
            vector<int> &v = a2i.at(*itr);
            a1 = v.end() - upper_bound(v.begin(), v.end(), j);
        }
        itr = lower_bound(as.begin(), as.end(), A[i]);
        if (a2i.at(A[i])[0] == i and itr != as.begin())
        {
            vector<int> &v = a2i.at(*prev(itr));
            a2 = lower_bound(v.begin(), v.end(), i) - v.begin();
        }
        chmax(ret, d + a1 + a2);
    }
    return N - ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}