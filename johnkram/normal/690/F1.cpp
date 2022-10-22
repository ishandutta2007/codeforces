#include<cstdio>
int c[10005],d[10005],n,i,j,k;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)c[i]=c[i-1]+i-1;
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&j,&k);
        d[j]++;
        d[k]++;
    }
    for(i=1,j=0;i<=n;i++)j+=c[d[i]];
    printf("%d\n",j);
    return 0;
}