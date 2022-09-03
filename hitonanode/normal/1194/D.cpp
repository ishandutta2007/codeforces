#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

bool solve()
{
    int N, K;
    cin >> N >> K;
    if (K % 3) return N % 3;
    return N % (K + 1) == K or (N % (K + 1)) % 3;
}

int main()
{
    int T;
    cin >> T;
    REP(_, T) if (solve()) puts("Alice"); else puts("Bob");
}