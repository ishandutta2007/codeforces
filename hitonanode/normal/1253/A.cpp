#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

bool solve()
{
    int N;
    cin >> N;
    vector<int> A(N + 2), B(N + 2);
    REP(i, N) cin >> A[i + 1];
    REP(i, N) cin >> B[i + 1];
    REP(i, N + 2)
    {
        B[i] -= A[i];
        if (B[i] < 0) return false;
    }
    int c = 0;
    REP(i, N + 1) if (B[i + 1] != B[i]) c++;
    return c <= 2;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "YES" : "NO") << endl;
}