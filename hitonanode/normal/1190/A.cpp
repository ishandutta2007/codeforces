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
    lint N, M, K;
    cin >> N >> M >> K;
    vector<lint> P(M);
    REP(i, M) cin >> P[i];

    int i = 0, ret = 0, used = 0;
    while (i < M)
    {
        lint pn_i = (P[i] - used + K - 1) / K;
        while (i + 1 < M and (P[i + 1] - used + K - 1) / K == pn_i) i++;
        ret++;
        i++;
        used = i;
    }
    cout << ret << endl;
}