#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long a[1005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    long long ans=0;
    for(int i=1;i<=n;i+=2)
    {
        long long Minn=0,Now=0;
        for(int j=i+1;j<=n;j++)
        {
            if(Minn<=a[i] && j%2==0 && !(Minn+Now>a[j] || a[i]+Now<0))
            {
                ans+=min(a[i],a[j]-Now)-max(Minn,0-Now);
                if(i+1!=j) ans++;
            }
            if(j%2==1) Now+=a[j];
            else Now-=a[j];
            Minn=-min(-Minn,Now);
        }
    }
    printf("%lld\n",ans);
}