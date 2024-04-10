#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,m,k[N],c[N];
ll a[N],b[N];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&k[i]);
        sort(k+1,k+1+n);
        for(int i=1;i<=m;i++) scanf("%d",&c[i]);
        c[m+1]=1e9;c[m+1]++;
        int tot=0;
        for(int i=1;i<=n;i++)
            if(tot<k[i]) tot++;
        for(int i=1;i<=n;i++) a[i]=a[i-1]+c[k[i]];
        for(int i=1;i<=m;i++) b[i]=b[i-1]+c[i];
        ll ans=1e18;
        for(int i=tot;i>=0;i--) ans=min(ans,b[i]+a[n-i]);
        printf("%lld\n",ans);
    }
}