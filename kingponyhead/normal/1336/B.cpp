// KingPonyHead
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 19, Mod = 1e9 + 7;
int n[2], m, q;
inline long long SQR(long long a)
{
    return (a * a);
}
inline long long Solve(vector < int > A, vector < int > B, vector < int > C)
{
    long long Mn = LLONG_MAX;
    for (int b : B)
    {
        int la = upper_bound(A.begin(), A.end(), b) - A.begin() - 1;
        int lc = lower_bound(C.begin(), C.end(), b) - C.begin();
        if (la >= 0 && lc < (int)C.size())
            Mn = min(Mn, SQR(A[la] - b) + SQR(A[la] - C[lc]) + SQR(C[lc] - b));
    }
    return (Mn);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q;
    for (; q; q --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vector < int > A, B, C;
        for (int i = 0; i < a; i ++)
        {
            int val;
            cin >> val;
            A.push_back(val);
        }
        for (int i = 0; i < b; i ++)
        {
            int val;
            cin >> val;
            B.push_back(val);
        }
        for (int i = 0; i < c; i ++)
        {
            int val;
            cin >> val;
            C.push_back(val);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        long long Mn = LLONG_MAX;
        Mn = min(Mn, Solve(A, B, C));
        Mn = min(Mn, Solve(A, C, B));
        Mn = min(Mn, Solve(B, A, C));
        Mn = min(Mn, Solve(B, C, A));
        Mn = min(Mn, Solve(C, A, B));
        Mn = min(Mn, Solve(C, B, A));
        printf("%lld\n", Mn);
    }
    return 0;
}