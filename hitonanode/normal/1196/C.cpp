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

constexpr int INF = 100000;
int main()
{
    int Q;
    cin >> Q;
    REP(_, Q)
    {
        int N;
        cin >> N;
        int xmin = -INF, xmax = INF, ymin = -INF, ymax = INF;
        REP(_, N)
        {
            int x, y;
            cin >> x >> y;
            vector<int> f(4);
            REP(i, 4) cin >> f[i];
            if (!f[0]) mmax(xmin, x);
            if (!f[1]) mmin(ymax, y);
            if (!f[2]) mmin(xmax, x);
            if (!f[3]) mmax(ymin, y);
        }
        if (ymax >= ymin and xmax >= xmin) printf("1 %d %d\n", xmin, ymin);
        else puts("0");
    }
}