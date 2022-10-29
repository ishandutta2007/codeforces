// Long Live The King
#include<bits/stdc++.h>
using namespace std;
int n, A[1001], M[1001], cnt;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i ++)
        if (!M[i])
        {
            M[i] = 1;
            for (int j = i; j <= n; j ++)
                if (A[j] % A[i] == 0)
                    M[j] = 1;
            cnt ++;
        }
    return !printf("%d\n", cnt);
}