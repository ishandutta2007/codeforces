#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<vector<lint>> dp;
vector<int> C;

constexpr lint INF = 4e18;
void update(int l, int s)
{
    dp[l].push_back(-INF);
    IREP(i, dp[l].size() - 1) if (mmax(dp[l][i + 1], dp[l][i] + C[l] - s))
    {
        int nb = i + 1; // 
        lint tmp = dp[l][i + 1];
        int h = l;
        while (nb)
        {
            h++;
            nb /= 2;
            tmp += 1LL * nb * C[h];
            if (nb >= dp[h].size()) dp[h].resize(nb + 1, -INF);
            mmax(dp[h][nb], tmp);
        }
        mmax(dp[h][0], tmp);
    }
    REP(i, dp.size() - 1) mmax(dp[i + 1][0], dp[i][0]);
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> L(N), S(N);
    cin >> L >> S;
    C.resize(N + M + 1);
    REP(i, N + M) cin >> C[i + 1];
    dp.assign(M + 20, {0});

    IREP(i, N) update(L[i], S[i]);
    cout << dp.back()[0] << endl;
}