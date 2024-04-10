#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n;
ll a[N],b[N];
bool judge(ll m)
{
    for(int i=1;i<=n;i++) b[i]=a[i];
    for(int i=2;i<=n;i++)
    {
        int k=-1;
        for(ll j=m;j>=0;j--)
            if(b[i]+(1ll<<j)<=b[i-1]) b[i]+=(1ll<<j);
        else k=j;
        if(b[i]<b[i-1]&&k==-1) return false;
        if(b[i]<b[i-1]) b[i]+=1ll<<k;
    }
    return true;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        bool flag=true;
        for(int i=2;i<=n;i++) if(a[i]<a[i-1]) flag=false;
        if(flag)
        {
            printf("0\n");continue;
        }
        ll l=0,r=32,ans;
        while(l<=r)
        {
            int m=l+r>>1;
            if(judge(m)) ans=m,r=m-1;
            else l=m+1;
        }
        printf("%lld\n",ans+1);
    }
}