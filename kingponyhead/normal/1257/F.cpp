// KingPonyHead
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, q, A[N];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        scanf("%d", &A[i]);
    int MAX = 1 << 15;
    vector < vector < int > > V;
    for (int i = 0; i < MAX; i ++)
    {
        vector < int > T(n, 0);
        for (int j = 0; j < n; j ++)
            T[j] = __builtin_popcount((A[j] & (MAX - 1)) ^ i);
        V.push_back(T);
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < MAX; i ++)
    {
        for (int cbit = 0; cbit <= 30; cbit ++)
        {
            vector < int > T(n, 0);
            for (int j = 0; j < n; j ++)
                T[j] = cbit - __builtin_popcount((A[j] >> 15) ^ i);
            int lb = lower_bound(V.begin(), V.end(), T) - V.begin();
            if (V[lb] == T)
            {
                for (int ii = 0; ii < MAX; ii ++)
                {
                    vector < int > TT(n, 0);
                    for (int j = 0; j < n; j ++)
                        TT[j] = __builtin_popcount((A[j] & (MAX - 1)) ^ ii);
                    if (TT == T)
                        return !printf("%d\n", ii | (i << 15));
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}