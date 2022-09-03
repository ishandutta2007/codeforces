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
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }


lint INF = 1e18 + 10;
lint solve()
{
    int N;
    cin >> N;
    vector<lint> A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i];
    vector<lint> dp(3);
    REP(i, N)
    {
        if (i == 0)
        {
            dp[1] = B[0] * 1;
            dp[2] = B[0] * 2;
        }
        else
        {
            vector<lint> dpnxt(3, INF);
            REP(j, 3) REP(k, 3)
            {
                if (A[i - 1] + j != A[i] + k)
                {
                    mmin(dpnxt[k], dp[j] + B[i] * k);
                }
            }
            dp = dpnxt;
        }
    }
    return *min_element(ALL(dp));
}

int main()
{
    int Q;
    cin >> Q;
    REP(_, Q)
    {
        cout << solve() << endl;
    }
}