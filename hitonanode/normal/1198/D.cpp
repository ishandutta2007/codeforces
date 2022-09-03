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
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////
 
int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    cin >> S;
    vector<vector<vector<vector<int>>>> dp;
    ndarray(dp, N, N, N, N); // dp[x][y][h][w]
    REP(i, N) REP(j, N) REP(k, N) REP(l, N) dp[i][j][k][l] = 10000;
    REP(x, N) REP(y, N) dp[x][y][0][0] = (S[x][y] == '#');

    vector<vector<int>> couH(N), couW(N);
    REP(i, N)
    {
        couH[i].resize(N + 1);
        REP(j, N) couH[i][j + 1] = couH[i][j] + (S[i][j] == '#');
        couW[i].resize(N + 1);
        REP(j, N) couW[i][j + 1] = couW[i][j] + (S[j][i] == '#');
    }
    REP(h, N) REP(w, N) REP(x, N - h) REP(y, N - w)
    {
        int ret = max(h, w) + 1;
        REP(hh, h + 1) if (couH[x + hh][y + w + 1] == couH[x + hh][y])
        {
            int tmp = 0;
            if (hh) tmp += dp[x][y][hh - 1][w];
            if (hh < h) tmp += dp[x + hh + 1][y][h - hh - 1][w];
            mmin(ret, tmp);
        }
        REP(ww, w + 1) if (couW[y + ww][x + h + 1] == couW[y + ww][x])
        {
            int tmp = 0;
            if (ww) tmp += dp[x][y][h][ww - 1];
            if (ww < w) tmp += dp[x][y + ww + 1][h][w - ww - 1];
            mmin(ret, tmp);
        }
        dp[x][y][h][w] = ret;
    }
    // dbg(dp);
    cout << dp[0][0][N - 1][N - 1] << endl;
}