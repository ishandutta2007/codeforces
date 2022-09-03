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
    int N;
    cin >> N;
    vector<lint> A(N);
    REP(i, N) cin >> A[i];
    lint tot = accumulate(ALL(A), 0LL);
    lint pa = A[0];
    vector<lint> ret{1};
    FOR(i, 1, N) if (A[i] * 2 <= A[0])
    {
        pa += A[i];
        ret.push_back(i + 1);
    }
    if (pa * 2 > tot)
    {
        printf("%d\n", (int)ret.size());
        REP(i, ret.size()) printf("%d ", ret[i]);
        puts("");
    }
    else
    {
        puts("0");
    }
}