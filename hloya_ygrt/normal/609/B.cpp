#include <bits\stdc++.h>

using namespace std;

int main()
{
    int zh[10]={0};
    int n,m;
    scanf("%d %d",&n,&m);

    int sum=0;

    for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            zh[x-1]++;
        }

    for (int i=0;i<10;i++)
    for (int j=i+1;j<10;j++)
    {
        sum+=zh[i]*zh[j];
    }
    printf("%d",sum);
    return 0;
}