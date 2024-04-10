#include<stdio.h>
#define MAX   100100
int m,n;
int f[MAX];
int pa;
void init(void)
{
    int i,c,t;
    f[0]=0;
    scanf("%d",&n);
    scanf("%d",&m);
    for (i=1;i<=n;i=i+1)
        {
            scanf("%d",&c);
            scanf("%d",&t);
            f[i]=f[i-1]+c*t;
        }   
}
void process(void)
{
    pa=1;
    int i,j,t;
    for (i=1;i<=m;i=i+1)
        {
            scanf("%d",&t);
            for (j=pa;j<=n;j=j+1)
                if ((f[j-1]<t) && (f[j]>=t))
                    {
                        printf("%d\n",j);
                        pa=j;
                        break;
                    }
        }
}
int main(void)
{
    init();
    process();
}