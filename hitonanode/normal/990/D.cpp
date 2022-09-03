#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    if (A > 1 and B > 1) {
        puts("NO");
        return 0;
    }
    int U = A + B - 1;
    vector<string> ret(N, string(N, '0'));

    if (A == 1 and B == 1) {
        if (N == 1) {
            puts("YES");
            puts("0");
            return 0;
        }
        if (N <= 3) {
            puts("NO");
            return 0;
        }
        REP(i, N - 1) ret[i][i + 1] = ret[i + 1][i] = '1';
    }
    else {
        FOR(i, 1, N - U + 1) ret[0][i] = ret[i][0] = '1';
        if (A == 1) {
            REP(i, N) REP(j, N) if (i != j) {
                ret[i][j] = '0' ^ '1' ^ ret[i][j];
            }
        }
    }
    puts("YES");
    for (auto s : ret) printf("%s\n", s.c_str());
}