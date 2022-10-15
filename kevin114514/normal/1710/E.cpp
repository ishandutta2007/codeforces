#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
#define ll long long
using namespace std;
int aaa[N],bbb[N],px[N],py[N],n,m;
ll sx[N],sy[N];
int xt,yt;
ll calc(int l,int r){return sx[r]-sx[l-1];}
ll sum(int x,int y,bool cut)
{
    int res=0;
    if(px[x]<y)
    {
        if(cut)
        {
            if(xt>x && yt>y) res=1;
            if(xt<=x && yt<=y && yt<=px[xt]) res=1;
        }
        int l=py[y];
        return 1ll*l*y+calc(l+1,x)+1ll*(n-x)*(m-y)-res;
    }
    
    if(cut)
    {
        if(xt<=x && yt<=y) res=1;
        if(xt>x && yt>y && yt>px[xt]) res=1;
    }
    int r=py[y];
    
    return 1ll*x*y+(1ll*(r-x)*m-calc(x+1,r))+1ll*(n-r)*(m-y)-res;
}
bool ck(int x)
{
    px[0]=m;
    for(int i=1;i<=n;i++)
        for(px[i]=px[i-1];px[i] && aaa[i]+bbb[px[i]]>x;px[i]--);
    for(int i=1;i<=n;i++) sx[i]=sx[i-1]+px[i];
    py[0]=n;
    for(int i=1;i<=m;i++)
        for(py[i]=py[i-1];py[i] && aaa[py[i]]+bbb[i]>x;py[i]--);
        
    ll a0=max(calc(1,n),1ll*n*m-calc(1,n)),a1=max(calc(1,n)-(yt<=px[xt]),1ll*n*m-calc(1,n)-(yt>px[xt]));
    int p=1;
    
    for(int i=1;i<=n;i++)
    {
        while(p<m && sum(i,p,0)<=sum(i,p+1,0)) p++;
        a0=max(a0,sum(i,p,0));
    }
    p=1;
    for(int i=1;i<=n;i++)
    {
        while(p<m && sum(i,p,1)<=sum(i,p+1,1)) p++;
        a1=max(a1,sum(i,p,1));
    }
    return a0!=a1+1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&aaa[i]);
    for(int i=1;i<=m;i++) scanf("%d",&bbb[i]);
    xt=aaa[1],yt=bbb[1];
    sort(aaa+1,aaa+n+1);sort(bbb+1,bbb+m+1);
    xt=lower_bound(aaa+1,aaa+n+1,xt)-aaa,yt=lower_bound(bbb+1,bbb+m+1,yt)-bbb;
    int l=aaa[1]+bbb[1],r=aaa[xt]+bbb[yt],res=aaa[xt]+bbb[yt];
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(ck(mid)) r=mid-1,res=mid;
        else l=mid+1;
    }
    printf("%d\n",res);
    return 0;
}