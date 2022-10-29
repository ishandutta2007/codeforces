// Long Live The King
#include<bits/stdc++.h>
using namespace std;
int n, A[1001], B[1001];
char S[1001];
int main()
{
    scanf("%d", &n);
    scanf("%s", &S);
    for (int i = 0; i < n; i ++)
        scanf("%d%d", &A[i], &B[i]);
    int Mx = 0;
    for (int i = 0; i < 100000; i ++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j ++)
        {
            int a = 0;
            if (i >= B[j])
                a += (i - B[j]) / A[j] + 1;
            if (a % 2 == 0)
                cnt += (S[j] == '1');
            else
                cnt += (S[j] == '0');
        }
        Mx = max(Mx, cnt);
    }
    return !printf("%d\n", Mx);
}