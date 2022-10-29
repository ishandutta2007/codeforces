// KingPonyHead
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, q, A[N];
int main()
{
    scanf("%d", &q);
    for (; q; q --)
    {
        int a, b;
        scanf("%d%d%d%d", &n, &m, &a, &b);
        printf("%d\n", min(abs(a - b) + m, n - 1));
    }
    return 0;
}