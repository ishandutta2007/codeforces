#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


bool solve()
{
    string A, B, C;
    cin >> A >> B >> C;
    REP(i, A.length()) if (A[i] != C[i] and B[i] != C[i]) return false;
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "YES" : "NO") << endl;
}