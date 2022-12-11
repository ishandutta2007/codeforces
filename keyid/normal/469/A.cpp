#include <cstdio>
#include <cstring>

int main()
{
    int n,p,x;
    bool c[101];
    memset(c,0,sizeof(c));
    scanf("%d%d",&n,&p);
    for (int i=0;i<p;i++)
    {
        int x;
        scanf("%d",&x);
        c[x]=true;
    }
    scanf("%d",&p);
    for (int i=0;i<p;i++)
    {
        int x;
        scanf("%d",&x);
        c[x]=true;
    }
    for (int i=1;i<=n;i++) 
      if (!c[i])
      {
        printf("Oh, my keyboard!");
        return 0;
      }
    printf("I become the guy.");
    return 0;
}