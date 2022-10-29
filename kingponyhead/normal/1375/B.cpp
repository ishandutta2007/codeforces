// Ponies everywhere ...
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1009, Mod = 1e9 + 7;
int n, m, q, A[N][N];
inline int Get(int a, int b)
{
    int cc = 0;
    if (a > 1) cc ++;
    if (a < n) cc ++;
    if (b > 1) cc ++;
    if (b < m) cc ++;
    return cc;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q;
    for (; q; q --)
    {
        cin >> n >> m;
        bool Fail = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
            {
                cin >> A[i][j];
                if (A[i][j] > Get(i, j))
                    Fail = 1;
            }
        if (Fail)
            {printf("NO\n"); continue;}
        printf("YES\n");
        for (int i = 1; i <= n; i ++, puts(""))
            for (int j = 1; j <= m; j ++)
                printf("%d ", Get(i, j));
    }
    return 0;
}