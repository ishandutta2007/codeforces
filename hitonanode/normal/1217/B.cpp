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
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }



int main()
{
    int T;
    cin >> T;
    REP(_, T)
    {
        lint n, x;
        cin >> n >> x;
        lint dmax = 0;
        lint dec_max = 0;
        REP(_, n)
        {
            lint d, h;
            cin >> d >> h;
            mmax(dmax, d);
            mmax(dec_max, d - h);
        }
        if (dec_max == 0 and dmax < x) puts("-1");
        else if (dmax >= x) puts("1");
        else printf("%lld\n", (x - dmax + dec_max - 1) / dec_max + 1);
    }
}