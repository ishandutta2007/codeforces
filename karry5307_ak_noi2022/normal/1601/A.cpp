#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,x,cnt[31];
int gcd(int x,int y)
{
    if(x>y) swap(x,y);
    if(x==0) return y;
    return gcd(y%x,x);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<=30;i++) cnt[i]=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            for(int i=0;i<=30;i++)
            {
                if(x%2) cnt[i]++;
                x/=2;
            }
        }
        int ans=0;
        for(int i=0;i<=30;i++)
        {
            ans=gcd(ans,cnt[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(ans%i==0) printf("%d ",i);
        }
        printf("\n");
    }
}