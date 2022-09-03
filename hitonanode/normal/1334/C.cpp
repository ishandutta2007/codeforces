#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


lint solve()
{
    int N;
    cin >> N;
    vector<lint> A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i];
    REP(i, N) B[i] = min(B[i], A[(i + 1) % N]);
    return accumulate(A.begin(), A.end(), 0LL) - accumulate(B.begin(), B.end(), 0LL) + *min_element(B.begin(), B.end());
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cout << solve() << "\n";
    }
}