#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

int main()
{
    int T;
    cin >> T;
    REP(_, T)
    {
        lint N, M;
        cin >> N >> M;
        vector<lint> rec{0};
        FOR(i, 1, 11)
        {
            rec.emplace_back(M * i % 10);
            if (rec.back() == 0) break;
        }
        int l = rec.size() - 1;
        printf("%lld\n", accumulate(ALL(rec), 0LL) * (N / M / l) + accumulate(rec.begin(), rec.begin() + 1 + (N / M % l), 0LL));
    }
}