#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int n,a[N],b[N];
bool solve(int x)
{
    int t=1<<x;
    for(int i=1;i<=n;i++) b[i]=a[i]%(2*t);
    sort(b+1,b+1+n);
    int ans=0;
    int l=n,r=n;
    for(int i=1;i<=n;i++)
    {
        while(l>i&&b[i]+b[l]>=t) l--;
        while(r>i&&b[i]+b[r]>=2*t) r--;
        //l=lower_bound(b+1,b+1+n,t-b[i])-b;
        //r=lower_bound(b+1,b+1+n,2*t-b[i])-b-1;
        l=max(l,i);
        if(l<=r)
            ans^=(r-l)&1;
        //cout<<i<<' '<<l<<' '<<r<<endl;
    }
    l=r=n;
    for(int i=1;i<=n;i++)
    {
        while(l>i&&b[i]+b[l]>=3*t) l--;
        while(r>i&&b[i]+b[r]>=4*t) r--;
        //l=lower_bound(b+1,b+1+n,3*t-b[i])-b;
        //r=lower_bound(b+1,b+1+n,4*t-b[i])-b-1;
        //cout<<i<<' '<<l<<' '<<r<<endl;
        l=max(l,i);
        if(l<=r)
            ans^=(r-l)&1;
    }
    //if(x>=4) return ans;
    //cout<<x<<' '<<ans<<endl;
    //for(int i=1;i<=n;i++)
    //    printf(i==n?"%d\n":"%d ",b[i]);
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=0;
    for(int i=0;i<=25;i++)
        if(solve(i))
        ans|=1<<i;
    printf("%d\n",ans);
}
/*
4
7 6 3 8
4

2
*/