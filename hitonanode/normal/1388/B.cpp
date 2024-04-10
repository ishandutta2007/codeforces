#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

string solve()
{
    int N;
    cin >> N;
    string ret(N, '9');
    REP(d, (N + 3) / 4) ret[N - 1 - d]--;
    return ret;
}
int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}