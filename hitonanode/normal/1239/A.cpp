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

constexpr lint MOD = 1000000007;

lint fib(lint n)
{
    lint dp0 = 2, dp1 = 0;
    REP(_, n)
    {
        lint dp1_nxt = dp0;
        dp0 = (dp1 + dp0) % MOD;
        dp1 = dp1_nxt % MOD;
    }
    return dp0 + dp1;
}

int main()
{
    lint N, M;
    cin >> N >> M;
    cout << (2 + fib(N - 1) - 2 + fib(M - 1) - 2) % MOD << endl;
}