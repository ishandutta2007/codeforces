#include <iostream>
#include <string>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


int main()
{
    int TC;
    cin >> TC;
    REP(_, TC)
    {
        string S, T;
        cin >> S >> T;
        int j = 0, N = S.length(), M = T.length();
        REP(i, N)
        {
            if (j < 0) break;
            if (S[i] == T[j])
            {
                j++;
                if (i + 1 == N or S[i + 1] != S[i])
                {
                    while (j < M and T[j] == T[j - 1]) j++;
                }
            }
            else j = -1;
        }
        cout << (j == M ? "YES" : "NO") << endl;
    }
}