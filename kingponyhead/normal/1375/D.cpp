// Ponies everywhere ...
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1009, Mod = 1e9 + 7;
int n, m, q, A[N], C[N];
inline int Mex()
{
    memset(C, 0, sizeof(C));
    for (int i = 0; i < n; i ++)
        C[A[i]] ++;
    int p = 0;
    while (C[p]) p ++;
    return (p);
}
inline bool Bad()
{
    for (int i = 1; i < n; i ++)
        if (A[i] < A[i - 1])
            return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q;
    for (; q; q --)
    {
        cin >> n;
        for (int i = 0; i < n; i ++)
            cin >> A[i];
        m = n;
        vector < int > V;
        while (Bad())
        {
            int x = Mex();
            if (x == n)
            {
                V.push_back(-- n);
                A[n] = x;
                continue;
            }
            V.push_back(x);
            A[x] = x;
        }
        assert((int)V.size() <= m * 2);
        printf("%d\n", (int)V.size());
        for (int a : V)
            printf("%d ", a + 1);
        printf("\n");
    }
    return 0;
}