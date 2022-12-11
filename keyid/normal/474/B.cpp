#include <cstdio>

int f[1000010];

int main()
{
    //freopen("read.txt","r",stdin);
    int n,cnt=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        for (int j=1;j<=a;j++) f[++cnt]=i;
    }
    int m;
    scanf("%d",&m);
    while (m--)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",f[x]);
    }
    return 0;
}