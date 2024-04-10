// KingPonyHead
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, q, A[N];
vector < int > V[N];
int main()
{
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d", &n);
        for (int i = 0; i <= n; i ++)
            V[i].clear();
        for (int i = 1; i <= n; i ++)
            scanf("%d", &A[i]), V[A[i]].push_back(i);
        int Mn = n + 1;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j < (int)V[i].size(); j ++)
                Mn = min(Mn, V[i][j] - V[i][j - 1] + 1);
        if (Mn > n)
            Mn = -1;
        printf("%d\n", Mn);
    }
    return 0;
}