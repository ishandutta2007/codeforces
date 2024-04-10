#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
int n,a[N],A,R,M;
ll pre[N],bk[N],b[N];
ll solve(ll h)
{
    int pos=lower_bound(a+1,a+1+n,h)-a;
    ll x=pre[pos-1],y=bk[pos];
    x=(ll)h*(pos-1)-x;
    y=y-(ll)h*(n-pos+1);
    ll ans=0;
    if(x<y)
    {
        ans+=min(A+R,M)*x;
        ans+=R*(y-x);
    }
    else
    {
        ans+=min(A+R,M)*y;
        ans+=A*(x-y);
    }
    return ans;
}
int main()
{
    scanf("%d%d%d%d",&n,&A,&R,&M);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=n;i>=1;i--) bk[i]=bk[i+1]+a[i];
    ll l=a[1],r=a[n];
    while(r-l>10)
    {
        ll ml=l+(r-l)/3,mr=r-(r-l)/3;
        ll s1=solve(ml),s2=solve(mr);
        if(s1<s2) r=mr;
        else l=ml;
    }
    ll ans=1e18;
    for(ll i=l;i<=r;i++) ans=min(ans,solve(i));
    printf("%lld\n",ans);
}