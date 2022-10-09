#include <cstdio>
#include <algorithm>
#define mod (1000000000)

using namespace std;

int val[200];
int fib[200];

int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    fib[0]=fib[1]=1;
    for (int i=2; i<=105; i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
        if (fib[i]>=mod) fib[i]-=mod;
    }
    for (int i=1; i<=n; i++)
    scanf("%d",&val[i]);
    while (m--)
    {
        int op;
        scanf("%d",&op);
        if (op==1)
        {
            int pl,vr;
            scanf("%d%d",&pl,&vr);
            val[pl]=vr;
        }
        else
        {
            int st,en;
            scanf("%d%d",&st,&en);
            long long ret=0;
            for (int i=0; i<=en-st; i++)
            ret=(ret+1ll*fib[i]*val[st+i])%mod;
            printf("%I64d\n",ret);
        }
    }
}