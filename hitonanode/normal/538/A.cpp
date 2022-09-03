#include <bits/stdc++.h>
using namespace std;

#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define REP(i, n) FOR(i, 0, n)

int main()
{
    string S;
    cin >> S;
    string T = "CODEFORCES";
    REP(i, T.length() + 1)
    {
        if (S.length() >= T.length() and S.substr(0, i) + S.substr(S.length() - T.length() + i) == T)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}