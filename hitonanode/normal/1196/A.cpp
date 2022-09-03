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



int main()
{
    int Q;
    cin >> Q;
    REP(_, Q)
    {
        vector<lint> a(3);
        REP(i, 3) cin >> a[i];
        sort(ALL(a));
        lint d = min(a[1] - a[0], a[2]);
        a[0] += d;
        a[2] -= d;
        a[0] += a[2] / 2;
        a[1] += a[2] / 2;
        printf("%lld\n", a[0]);
    }
}