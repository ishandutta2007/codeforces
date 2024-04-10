#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
long long And[10005],Or[10005],a[10005];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=2;i<=n;i++)
    {
        printf("and 1 %d\n",i);
        fflush(stdout);
        scanf("%lld",&And[i]);
        printf("or 1 %d\n",i);
        fflush(stdout);
        scanf("%lld",&Or[i]);
    }
    long long tmpA,tmpO;
    printf("and 2 3\n");
    fflush(stdout);
    scanf("%lld",&tmpA);
    printf("or 2 3\n");
    fflush(stdout);
    scanf("%lld",&tmpO);
    long long tmp=And[2]+Or[2]+And[3]+Or[3]+tmpA+tmpO;
    a[1]=tmp/2-tmpA-tmpO;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=30;j++)
        {
            if(a[1] & (1<<j)) a[i]+=(And[i] & (1<<j));
            else  a[i]+=(Or[i] & (1<<j));
        }
    }
    sort(a+1,a+n+1);
    printf("finish %d\n",a[k]);
}