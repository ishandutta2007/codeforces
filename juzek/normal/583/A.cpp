#include <bits/stdc++.h>
using namespace std;

bool h[57];
bool v[57];

int main()
{
    int N;
    scanf("%d",&N);
    N *= N;
    int a,b;
    for (int i = 1;i <= N;i++)
    {
        scanf("%d%d",&a,&b);
        if (!h[a] && !v[b])
        {
            printf("%d ",i);
            h[a] = true;
            v[b] = true;
        }
    }
    return 0;
}