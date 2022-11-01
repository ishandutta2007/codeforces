#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        long long ans=1e18;
        if(abs(c-b)%d==0) ans=abs(c-b)/d;
        if((c-1)%d==0)
        {
            long long k=(b-1)/d;
            if(b-d*k>1) k++;
            ans=min(ans,k+(c-1)/d);
        }
        if((a-c)%d==0)
        {
            long long k=(a-b)/d;
            if(b+d*k<a) k++;
            ans=min(ans,k+(a-c)/d);
        }
        if(ans==1e18) ans=-1;
        printf("%lld\n",ans);
    }
}