#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sub(const pair<ll,ll> &line,ll x)
{
    return line.first*x+line.second;
}
double intersect(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    return (b.second-a.second)/(a.first-b.first+0.0);//m1x+c1=m2x+c2 > (c2-c1)/(m1-m2);
}
struct node
{
    node *l,*r;
    pair<ll,ll> line;

    node()
    {
        l=r=NULL;
    }
} *root;
void insert(pair<ll,ll> line,node *&cur=root,int ns=-1000000,int ne=1000000)
{

    //cout<<ns<<" "<<ne<<endl;
    if(cur==NULL)
        {cur=new node();cur->line=line;return;}
    if(line.first==cur->line.first)
    {
        cur->line=max(line,cur->line);
        return;
    }
    double x=intersect(line,cur->line);
    if(x<ns||x>ne)
    {
        if(sub(line,ns)>sub(cur->line,ns))
            cur->line=line;
        return;
    }
    if(ns==ne)
    {
        if(sub(line,ne)>sub(cur->line,ne))
            swap(line,cur->line);
            return;
    }
    int md=ns+(ne-ns)/2;
    if(x<=md)
    {
        if(sub(line,ne)>sub(cur->line,ne))
            swap(line,cur->line);
        insert(line,cur->l,ns,md);
    }
    else
    {
        if(sub(line,ns)>sub(cur->line,ns))
            swap(line,cur->line);
        insert(line,cur->r,md+1,ne);
    }
}
long long query(int x,node *&cur=root,int ns=-1000000,int ne=1000000)
{
    if(x<ns||x>ne||cur==NULL)
        return LLONG_MIN;
    ll ret=sub(cur->line,x);
    if(ns==ne)
        return ret;
    int md=ns+(ne-ns)/2;
    ret=max(ret,query(x,cur->l,ns,md));
    ret=max(ret,query(x,cur->r,md+1,ne));
    return ret;
}
ll sum[200009];
int a[200009];
void solve()
{
    root=NULL;
    int n;
    ll ans=0,res=0;
    scanf("%d",&n);
    sum[0]=0;
    for(int i=1;i<=n;i++){
     scanf("%d",&a[i]);
    sum[i]=sum[i-1]+a[i];ans+=a[i]*1LL*i;}
    for(int i=n;i>=1;i--)
    {   insert({i,-sum[i]});
        res=max(res,query(a[i])+sum[i]-a[i]*1LL*i);}
    root=NULL;
    for(ll i=1;i<=n;i++)
    {
        insert({i,-sum[i-1]});
        res=max(res,query(a[i])+sum[i-1]-a[i]*1LL*i);
    }
   printf("%I64d",ans+res);
}
int main()
{
    solve();
    return 0;
}