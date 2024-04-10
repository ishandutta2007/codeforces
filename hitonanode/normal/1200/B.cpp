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
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int main()
{
    int T;
    cin >> T;
    REP(_, T)
    {
        lint N, M, K;
        cin >> N >> M >> K;
        vector<lint> H(N);
        REP(i, N) cin >> H[i];
        REP(i, N - 1)
        {
            lint d = H[i + 1] - H[i] - K;
            if (d > 0)
            {
                M -= d;
            }
            else
            {
                M += min(abs(d), H[i]);
            }
            if (M < 0) break;
        }
        if (M < 0) puts("NO");
        else puts("YES");
    }
}