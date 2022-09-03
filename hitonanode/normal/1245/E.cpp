#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int main()
{
    vector<vector<int>> H(10, vector<int>(10));
    cin >> H;
    vector<vector<double>> dp(10, vector<double>(10));
    vector<vector<double>> dp2(10, vector<double>(10));
    vector<double> dpseq;
    REP(i, 100)
    {
        int h = i / 10;
        int w = i % 10;
        if (h % 2) w = 9 - w;
        double tmp = 0.0;

        if (i == 0) tmp = 0.0;
        else if (i <= 6) tmp = 6.0;
        else
        {
            tmp = accumulate(dpseq.end() - 6, dpseq.end(), 0.0) / 6 + 1;
        }
        dp2[h][w] = tmp;
        if (H[h][w])
        {
            mmin(tmp, dp2[h - H[h][w]][w]);
        }
        dp[h][w] = tmp;
        dpseq.push_back(tmp);
    }
    cout << dp[9][0] << endl;
}