#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;



int main()
{
    int N, R;
    cin >> N >> R;
    vector<int> F(N), S(N), P(N);
    REP(i, N) cin >> F[i] >> S[i] >> P[i];

    double lo = 0.0, hi = 1e10;
    REP(_, 100)
    {
        double c = (lo + hi) / 2;
        if (lo * hi > 1.1)
        {
            c = sqrt(lo * hi);
        }
        vector<vector<double>> dp(N + 1, vector<double>(R + 1));
        IREP(i, N) REP(r, R + 1)
        {
            double pfast = P[i] / 100.0;
            double exp_go = 0.0;
            if (r + F[i] <= R) exp_go += pfast * (F[i] + dp[i + 1][r + F[i]]);
            else exp_go += pfast * (F[i] + c);

            if (r + S[i] <= R) exp_go += (1.0 - pfast) * (S[i] + dp[i + 1][r + S[i]]);
            else exp_go += (1.0 - pfast) * (S[i] + c);
            dp[i][r] = min(c, exp_go);
        }
        // dbg(dp);
        (dp[0][0] >= c ? lo : hi) = c;
    }
    cout << hi << '\n';
}