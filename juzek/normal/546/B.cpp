#include <bits/stdc++.h>
using namespace std;

int il[9000007];

int main()
{
    int N;
    scanf("%d",&N);
    int a;
    for (int i = 0;i < N;i++)
    {
        scanf("%d",&a);
        il[a]++;
    }
    N *= N;
    N += 4;
    int odp = 0;
    for (int i = 1;i <= N;i++)
    {
        if (il[i] > 1)
        {
            il[i+1] += il[i]-1;
            odp += il[i]-1;
            il[i] = 1;
        }
    }
    printf("%d",odp);
    return 0;
}