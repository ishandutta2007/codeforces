#include<cstdio>
using namespace std;
int n,t,x,sum;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            sum+=x;
        }
        printf("%d\n",sum%n==0 ? 0 : 1);
    }
}