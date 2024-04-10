// Long Live The King
#include<bits/stdc++.h>
using namespace std;
const int N = 30, M = 2030, MXK = 1 << 13;
int n, m, A[N][M], Mark[M], dp[MXK], dpt[MXK], dpf[MXK], B[N][M];
int main()
{
    int q;
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d%d", &n, &m);
        vector < pair < int , int > > PR;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                scanf("%d", &A[i][j]), PR.push_back(make_pair(A[i][j], j));
        sort(PR.begin(), PR.end());
        reverse(PR.begin(), PR.end());
        assert(PR.size() == n * m);
        memset(Mark, 0, sizeof(Mark));
        int ts = 0;
        for (int i = 0; i < n * m && ts < 110; i ++)
            if (Mark[PR[i].second] == 0)
            {
                for (int h = 0; h < n; h ++)
                    B[h][ts] = A[h][PR[i].second];
                Mark[PR[i].second] = 1; ts ++;
            }
        assert(ts == m);
        m = ts;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                B[i + n][j] = B[i][j];
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < m; j ++)
        {
            memset(dpt, 0, sizeof(dpt));
            memcpy(dpf, dp, sizeof(dp));
            for (int shft = 0; shft < n; shft ++)
            {
                memcpy(dp, dpf, sizeof(dp));
                for (int mask = 0; mask < (1 << n); mask ++)
                    for (int h = 0; h < n; h ++)
                        if ((mask >> h) & 1)
                            dp[mask] = max(dp[mask], dp[mask ^ (1 << h)] + B[h + shft][j]);
                for (int mask = 0; mask < (1 << n); mask ++)
                    dpt[mask] = max(dpt[mask], dp[mask]);
            }
            memcpy(dp, dpt, sizeof(dp));
        }
        printf("%d\n", dp[(1 << n) - 1]);
    }
    return 0;
}