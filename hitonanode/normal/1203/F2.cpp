#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }

int main()
{
    int N, R;
    cin >> N >> R;
    vector<pint> inc, dec;
    REP(_, N)
    {
        int A, B;
        cin >> A >> B;
        if (B >= 0) inc.emplace_back(A, B);
        else {
            int apb = A + B;
            if (apb < 0) A -= apb;
            dec.emplace_back(A + B, -B);
        }
    }
    sort(inc.begin(), inc.end());
    int ret = 0;
    for (auto pa : inc)
    {
        if (pa.first <= R) {
            R += pa.second;
            ret++;
        }
    }

    vector<int> dp(R + 1);
    sort(dec.begin(), dec.end());
    for (auto pa : dec)
    {
        IFOR(i, max(0, pa.first), R - pa.second + 1) mmax(dp.at(i + pa.second), dp.at(i) + 1);
    }
    cout << ret + dp[R] << endl;
}