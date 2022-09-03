#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////


int solve()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> AT(M, vector<int>(N));
    REP(i, N) REP(j, M) cin >> AT[j][i];

    vector<pint> p(M);
    REP(j, M) p[j] = pint(*max_element(ALL(AT[j])), j);
    sort(p.rbegin(), p.rend());
    vector<vector<int>> B(N, vector<int>(N));
    REP(i, min(N, M)) REP(j, N) B[i][j] = AT[p[i].second][j];

    vector<int> dp(1 << N);
    for (auto vec : B)
    {
        vector<int> dp_nxt(1 << N);
        REP(i, N)
        {
            vector<int> dp_tmp = dp;
            REP(j, N) REP(s, 1 << N)
            {
                int d = (i + j) % N;
                if (s & (1 << d))
                {
                    mmax(dp_tmp[s], dp_tmp[s - (1 << d)] + vec[j]);
                }
            }
            REP(s, 1 << N) mmax(dp_nxt[s], dp_tmp[s]);
        }
        REP(s, 1 << N) mmax(dp[s], dp_nxt[s]);
    }
    return dp.back();
}


int main()
{
    int TC;
    cin >> TC;
    REP(_, TC)
    {
        cout << solve() << endl;
    }
}