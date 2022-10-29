// Screw this ..
#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, k, A[N];
inline int Solve(int md)
{
    int Cnt = 0;
    for (int i = 1; i <= n; i ++)
        if (A[i] <= md)
            Cnt ++, Cnt += i != n, i ++;
    if (Cnt >= k)
        return 1;
    Cnt = 1;
    for (int i = 2; i <= n; i ++)
        if (A[i] <= md)
            Cnt ++, Cnt += i != n, i ++;
    return (Cnt >= k);
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &A[i]);
    int le = 0, ri = 1e9 + 1, md;
    while (ri - le > 1)
    {
        md = (le + ri) >> 1;
        if (Solve(md))
            ri = md;
        else
            le = md;
    }
    return !printf("%d\n", ri);
}