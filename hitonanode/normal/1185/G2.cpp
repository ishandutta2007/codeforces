#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
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

constexpr int MOD = 1000000007;
int N, T;
constexpr int M = 25;

vector<vector<int>> build_mat(vector<int> t)
{
    sort(t.rbegin(), t.rend());
    int nmax = min(M, (int)t.size());
    int tmax = accumulate(t.begin(), t.begin() + nmax, 0);
    vector<vector<int>> ret(nmax + 1, vector<int>(tmax + 1));
    ret[0][0] = 1;
    for (auto v : t)
    {
        IREP(n, nmax) IREP(j, tmax - v + 1)
        {
            ret[n + 1][j + v] += ret[n][j];
            if (ret[n + 1][j + v] >= MOD) ret[n + 1][j + v] -= MOD;
        }
    }
    return ret;
}
int main()
{
    cin >> N >> T;
    vector<vector<int>> t(3);
    REP(_, N)
    {
        int s, g;
        cin >> s >> g;
        t[g - 1].push_back(s);
    }

    vector<vector<vector<int>>> mat(3);
    REP(i, 3) mat[i] = build_mat(t[i]);

    vector<vector<vector<vector<int>>>> dp;
    ndarray(dp, M + 1, M + 1, M + 1, 4);
    REP(d, 4) dp[0][0][0][d] = 1;
    REP(i, M + 1) REP(j, M + 1) REP(k, M + 1) if (i + j + k)
    {
        lint tmp3 = 0;
        if (i) tmp3 += (lint)dp[i - 1][j][k][0] * i;
        if (j) tmp3 += (lint)dp[i][j - 1][k][1] * j;
        if (k) tmp3 += (lint)dp[i][j][k - 1][2] * k;
        dp[i][j][k][3] = tmp3 % MOD;
        REP(d, 3)
        {
            lint tmp = 0;
            REP(dd, 3) if (dd != d)
            {
                if (i and dd == 0) tmp += (lint)dp[i - 1][j][k][dd] * i;
                if (j and dd == 1) tmp += (lint)dp[i][j - 1][k][dd] * j;
                if (k and dd == 2) tmp += (lint)dp[i][j][k - 1][dd] * k;
            }
            dp[i][j][k][d] = tmp % MOD;
        }
    }

    int ret = 0;
    int N0 = mat[0].size() - 1, T0 = mat[0][0].size() - 1;
    int N1 = mat[1].size() - 1, T1 = mat[1][0].size() - 1;
    int N2 = mat[2].size() - 1, T2 = mat[2][0].size() - 1;

    REP(t0, T0 + 1) REP(t1, min(T1, T - t0) + 1)
    {
        int t2 = T - t0 - t1;
        if (t2 < 0 or t2 > T2) continue;
        REP(n0, N0 + 1) if (mat[0][n0][t0]) REP(n1, N1 + 1) if (mat[1][n1][t1]) REP(n2, N2 + 1) if (mat[2][n2][t2])
        {
            ret += (lint)mat[0][n0][t0] * mat[1][n1][t1] % MOD * mat[2][n2][t2] % MOD * dp[n0][n1][n2][3] % MOD;
            if (ret >= MOD) ret -= MOD;
        }
    }
    cout << ret << endl;
}