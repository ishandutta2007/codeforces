#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,m,ans[N],t[4*N];
ll k;
struct node
{
    ll x;
    int id;
    node(){x=id=0;}
    bool operator<(const node&o)const
    {
        if(x==o.x) return id<o.id;
        return x<o.x;
    }
}a[N],b[N];
void fix(int l,int r,int k,int x)
{
    if(l==r)
    {
        t[k]++;return;
    }
    int m=l+r>>1;
    if(x<=m) fix(l,m,k<<1,x);
    else fix(m+1,r,k<<1|1,x);
    t[k]=t[k<<1]+t[k<<1|1];
}
int query(int l,int r,int k,int v)
{
    if(l==r) return l;
    int m=l+r>>1;
    if(v<=t[k<<1]) return query(l,m,k<<1,v);
    return query(m+1,r,k<<1|1,v-t[k<<1]);
}
int main()
{
    int up=0;
    scanf("%d%d%lld",&n,&m,&k);
    if(m==1)
    {
        for(int i=1;i<=k;i++)
            printf("1\n");
        return 0;
    }
    for(int i=1;i<=m;i++)
        a[i].id=i;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x].x++;
    }
    sort(a+1,a+1+m);
    for(int i=1;i<=k;i++)
        scanf("%lld",&b[i].x),b[i].id=i;
    sort(b+1,b+1+k);
    int now=1;
    ll sum=0;
    for(int i=1;i<=k;i++)
    {
        b[i].x-=n;
        while(now<=m&&(ll)a[now].x*now-sum-a[now].x<b[i].x)
        {
            sum+=a[now].x;
            fix(1,m,1,a[now].id),now++;
        }
        ll t=b[i].x-a[now-1].x*(now-1)+sum;
        if(t%(now-1)==0) t=now-1;
        else t=t%(now-1);
        ans[b[i].id]=query(1,m,1,t);
    }
    for(int i=1;i<=k;i++)
        printf("%d\n",ans[i]);
}