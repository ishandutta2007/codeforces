#include<bits/stdc++.h>
using namespace std;
long long h,n,a[200005],b[200005];
int main()
{
    scanf("%lld%lld",&h,&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),b[i]=b[i-1]+a[i];
    long long ans=1e18;
    for(long long i=1;i<=n;i++)
        if(h+b[i]<=0)
            ans=min(ans,i);
    if(b[n]>=0&&ans==1e18)
        printf("-1\n");
    else if(ans!=1e18)
        printf("%lld\n",ans);
    else
    {
        for(long long i=1;i<=n;i++)
        {
            long long t=h+b[i];
            long long res=i+n*(t/-b[n]);
            //cout<<t/-b[n]<<endl;
            t=t-t/-b[n]*-b[n];
            if(t) res+=n;
            //cout<<i<<' '<<b[i]<<' '<<res<<' '<<t<<endl;
            ans=min(ans,res);
        }
        cout<<ans<<endl;
    }
}