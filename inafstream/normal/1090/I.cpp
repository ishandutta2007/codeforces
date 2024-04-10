#include <bits/stdc++.h>
using namespace std;

long long pre[10000005],nxt[10000005],a[10000005],n,m,i,j,tt,fi,mem[10000005];
long long b[10000005],x,y,z,l,r;

int main()
{
    scanf("%I64d",&tt);
    
    while (tt--)
    {
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&n,&l,&r,&x,&y,&z,&b[1],&b[2]);
        
        for (i=3;i<=n;i++) b[i]=((b[i-2]*x+b[i-1]*y+z)%4294967296ll+4294967296ll)%4294967296ll;
        for (i=1;i<=n;i++) a[i]=b[i]%(r-l+1)+l;
        //for (i=1;i<=n;i++) cerr<<a[i]<<' ';cerr<<endl;
        
        long long ans=(1ll<<63)-1;
        
        long long f=(1ll<<63)-1;
        for (i=1;i<=n;i++)
        {
            if (f>a[i]) f=a[i];
            if (f<a[i]) ans=min(ans,f*a[i]);
        }
        f=-((1ll<<63)-1);
        for (i=n;i>=1;i--)
        {
            if (f<a[i]) f=a[i];
            if (f>a[i]) ans=min(ans,f*a[i]);
        }
        
        if (ans==(1ll<<63)-1) puts("IMPOSSIBLE"); else printf("%I64d\n",ans);
        
    }
    
    return 0;
}