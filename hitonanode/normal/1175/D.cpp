#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

int N, K;

int main()
{
    cin >> N >> K;
    vector<lint> A(N);
    REP(i, N) cin >> A[i];
    vector<lint> accA(N + 1);
    IREP(i, N) accA[i] = A[i] + accA[i + 1];
    sort(accA.rbegin() + 1, accA.rend() - 1);
    cout << accumulate(accA.begin(), accA.begin() + K, 0LL) << endl;
}