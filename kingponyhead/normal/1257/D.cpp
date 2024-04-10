// KingPonyHead
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10;
int n, m, q, A[N], MX[N], S[N];
pair < int , int > B[N];
inline void Set(int i, int val)
{
    S[i += n - 1] = val;
    for (; i; i >>= 1)
        S[i >> 1] = max(S[i], S[i ^ 1]);
}
inline int GetMax(int l, int r)
{
    int Mx = 0;
    l += n - 1;
    r += n - 1;
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1) Mx = max(Mx, S[l ++]);
        if (r & 1) Mx = max(Mx, S[-- r]);
    }
    return (Mx);
}
int main()
{
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d", &n);
        for (int i = 0; i <= n + n + 5; i ++)
            S[i] = MX[i] = 0;
        for (int i = 1; i <= n; i ++)
            scanf("%d", &A[i]), Set(i, A[i]);
        scanf("%d", &m);
        for (int i = 1; i <= m; i ++)
            scanf("%d%d", &B[i].x, &B[i].y);
        sort(B + 1, B + m + 1);
        MX[m + 1] = 0;
        for (int i = m; i; i --)
            MX[i] = max(MX[i + 1], B[i].y);
        int nw = 1, cnt = 0;
        bool fail = 0;
        while (nw <= n)
        {
            int le = nw - 1, ri = n + 1, md;
            while (ri - le > 1)
            {
                md = (le + ri) >> 1;
                int Mx = GetMax(nw, md + 1);
                int lb = lower_bound(B + 1, B + m + 1, pair < int , int > {Mx, -1}) - B;
                if (lb == m + 1 || MX[lb] < md - nw + 1)
                    ri = md;
                else
                    le = md;
            }
            if (le == nw - 1)
                {fail = 1; break;}
            nw = le + 1;
            cnt ++;
        }
        if (fail)
            printf("-1\n");
        else
            printf("%d\n", cnt);
    }
    return 0;
}