#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

void solve()
{
    int N;
    cin >> N;
    vector<lint> A(N);
    cin >> A;
    lint tot = accumulate(ALL(A), 0LL);
    lint xo = 0;
    for (auto a : A) xo ^= a;
    tot += xo;
    printf("2\n%lld %lld\n", xo, tot);
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}