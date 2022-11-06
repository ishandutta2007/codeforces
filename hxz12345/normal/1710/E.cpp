//https://www.cnblogs.com/Flying2018/p/acmicpc2874.html
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 300010
#define ll long long
using namespace std;
int a[N],b[N],px[N],py[N],n,m;
ll sx[N],sy[N];
int tx,ty;
ll xsum(int l,int r){return sx[r]-sx[l-1];}
ll sum(int x,int y,bool cut)
{
    int res=0;
    if(px[x]<y)
    {
        if(cut)
        {
            if(tx>x && ty>y) res=1;
            if(tx<=x && ty<=y && ty<=px[tx]) res=1;
        }
        int l=py[y];
        return 1ll*l*y+xsum(l+1,x)+1ll*(n-x)*(m-y)-res;
    }
    if(cut)
    {
        if(tx<=x && ty<=y) res=1;
        if(tx>x && ty>y && ty>px[tx]) res=1;
    }
    int r=py[y];
    return 1ll*x*y+(1ll*(r-x)*m-xsum(x+1,r))+1ll*(n-r)*(m-y)-res;
}
bool check(int x)
{
    px[0]=m;
    for(int i=1;i<=n;i++)
        for(px[i]=px[i-1];px[i] && a[i]+b[px[i]]>x;px[i]--);
    for(int i=1;i<=n;i++) sx[i]=sx[i-1]+px[i];
    py[0]=n;
    for(int i=1;i<=m;i++)
        for(py[i]=py[i-1];py[i] && a[py[i]]+b[i]>x;py[i]--);
    ll a0=max(xsum(1,n),1ll*n*m-xsum(1,n)),a1=max(xsum(1,n)-(ty<=px[tx]),1ll*n*m-xsum(1,n)-(ty>px[tx]));
    int p=1;
    for(int i=1;i<=n;i++)
    {
        while(p<m && sum(i,p,0)<=sum(i,p+1,0)) p++;
        a0=max(a0,sum(i,p,0));
    }
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=m;j++)
    //         a0=max(a0,sum(i,j,0));
    p=1;
    for(int i=1;i<=n;i++)
    {
        while(p<m && sum(i,p,1)<=sum(i,p+1,1)) p++;
        a1=max(a1,sum(i,p,1));
    }
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=m;j++) a1=max(a1,sum(i,j,1));
    return a0!=a1+1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    tx=a[1],ty=b[1];
    sort(a+1,a+n+1);sort(b+1,b+m+1);
    tx=lower_bound(a+1,a+n+1,tx)-a,ty=lower_bound(b+1,b+m+1,ty)-b;
    int l=a[1]+b[1],r=a[tx]+b[ty],res=a[tx]+b[ty];
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1,res=mid;
        else l=mid+1;
    }
    printf("%d\n",res);
    return 0;
}