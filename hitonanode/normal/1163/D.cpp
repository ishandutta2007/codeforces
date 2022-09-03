#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
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
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
#define FI first
#define SE second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))

constexpr int INF = 1e9;

vector<int> mp_algorithm(const string &vec)
{
    int N = vec.size();
    vector<int> a(N + 1);
    a[0] = -1;
    int j = -1;
    REP(i, N)
    {
        while (j >= 0 and vec[i] != vec[j]) j = a[j];
        a[i + 1] = ++j;
    }
    return a;
}

vector<vector<int>> build(string S)
{
    int N = S.length();
    vector<vector<int>> ret(N + 1); // ic
    for (int i = 0; i <= N; i++)
    {
        ret[i].resize(26);
        for (int c = 0; c < 26; c++)
        {
            string str_nxt = S.substr(0, i) + (char)('a' + c);
            for (int l = 0; l <= min((int)str_nxt.length(), N); l++) if (str_nxt.substr(str_nxt.length() - l) == S.substr(0, l)) ret[i][c] = l;
        }
    }
    return ret;
}
int main()
{
    string C, S, T;
    cin >> C >> S >> T;
    vector<int> mp_S = mp_algorithm(S), mp_T = mp_algorithm(T);

    int I = C.length(), J = S.length(), K = T.length();

    vector<vector<int>> trans_S = build(S), trans_T = build(T);
    
    vector<vector<vector<int>>> dp;
    ndarray(dp, I + 1, J + 1, K + 1);
    for (auto &mat : dp) for (auto &vec : mat) for (auto &v : vec) v = -INF;
    dp[0][0][0] = 0;
    REP(i, I) REP(j, J + 1) REP(k, K + 1) if (dp[i][j][k] > -INF)
    {
        REP(c, 26) if (C[i] == (char)('a' + c) or C[i] == '*')
        {
            int nxj = trans_S[j][c];
            int nxk = trans_T[k][c];
            mmax(dp[i + 1][nxj][nxk], dp[i][j][k] + (nxj == J) - (nxk == K));
        }
    }
    int ret = -INF;
    for (auto vec : dp.back()) for (auto v : vec) mmax(ret, v);
    cout << ret << endl;
}