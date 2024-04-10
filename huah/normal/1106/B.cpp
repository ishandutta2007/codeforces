#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int num[100005];
struct node
{
    ll x,id;
}a[100005],b[100005];
bool cmp(node p1,node p2)
{
    if(p1.x==p2.x) return p1.id<p2.id;
    return p1.x<p2.x;
}
int main()
{
    ll x,y;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&num[i]),a[i].id=i;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i].x),b[i]=a[i];
    sort(b+1,b+1+n,cmp);
    int p=1;
    while(m--)
    {
        scanf("%lld%lld",&x,&y);
        ll ans=0;
        if(num[x]>=y) ans+=a[x].x*y,num[x]-=y,y=0;
        else
        {
            ans+=a[x].x*num[x],y-=num[x],num[x]=0;
            while(y&&p<=n)
            {
                if(num[b[p].id]>=y) ans+=b[p].x*y,num[b[p].id]-=y,y=0;
                else ans+=b[p].x*num[b[p].id],y-=num[b[p].id],num[b[p].id]=0,p++;
            }
            if(y) ans=0;
        }
        printf("%lld\n",ans);
    }
}