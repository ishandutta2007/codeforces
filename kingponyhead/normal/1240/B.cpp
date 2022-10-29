// KingPonyHead
#include<bits/stdc++.h>
using namespace std;
const int N = 600005;
int n, q, A[N], dp[N];
vector < int > V[N];
int main()
{
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &A[i]), V[A[i]].push_back(i);
        int cnt = 0;
        dp[0] = 0;
        int lst = -1;
        for (int i = 1; i <= n; i ++)
            if (V[i].size())
            {
                cnt ++;
                if (lst != -1 && V[i][0] > V[lst].back())
                    dp[i] = dp[lst] + 1;
                else
                    dp[i] = 1;
                lst = i;
            }
        printf("%d\n", cnt - *max_element(dp + 1, dp + n + 1));
        for (int i = 0; i <= n; i ++)
            dp[i] = 0, V[i].clear();
    }
    return 0;
}