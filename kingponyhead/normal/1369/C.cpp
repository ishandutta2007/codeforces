// Screw this ..
#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, k, A[N], W[N];
int main()
{
    int q;
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i ++)
            scanf("%d", &A[i]);
        for (int i = 0; i < k; i ++)
            scanf("%d", &W[i]);
        sort(W, W + k);
        sort(A, A + n);
        int l = 0;
        long long SM = 0;
        while (l < k && W[l] == 1)
            l ++, SM += A[-- n] * 2LL;
        int r = k, le = 0;
        while (r > l)
        {
            r --;
            SM += A[le] + A[-- n];
            le += W[r] - 1;
        }
        printf("%lld\n", SM);
    }
    return 0;
}