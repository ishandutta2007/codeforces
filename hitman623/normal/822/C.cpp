#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml unordered_map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector < ml > seg(800005);
ml ::iterator it;
long n,x,ans=(long)2e9+7,i,cur,d,f,g;
vector < pair < pll ,long > > a(200005);
void build(long node , long start , long end)
{
    long mid,m;
    if(start==end) seg[node][a[start].x.y-a[start].x.x+1]=a[start].y;
    else
    {
        mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        seg[node]=seg[2*node];
        for(it=seg[2*node+1].begin();it!=seg[2*node+1].end();it++)
        if(seg[node][it->first]==0)
        seg[node][it->first]=it->y;
        else seg[node][it->x]=min(seg[node][it->x],it->y);
    }
}

long query(long node , long start , long end , long l , long r,long val)
{
    long mid,p1,p2,m;
    if(l>end || r<start || start>end) return 2e9+7;
    if(start>=l && end<=r) return (seg[node][val]==0)?2e9+7:seg[node][val];
    else
    {
        mid=(start+end)/2;
        p1=query(2*node,start,mid,l,r,val);
        p2=query(2*node+1,mid+1,end,l,r,val);
        return min(p1,p2);
    }
}
int main()
{
    io
    cin>>n>>x;
    for(i=0;i<n;++i)
    cin>>a[i].x.x>>a[i].x.y>>a[i].y;
    sort(a.begin(),a.begin()+n);
    build(1,0,n-1);
    pair < pll , long > temp;
    for(i=0;i<n;++i)
    {
        cur=a[i].y;
        d=x-(a[i].x.y-a[i].x.x+1);
        if(d<0) continue;
        temp.x.x=a[i].x.y;
        temp.x.y=(long)2e9+7;
        temp.y=(long)2e9+7;
        f=upper_bound(a.begin()+i,a.begin()+n,temp)-a.begin();
        if((g=query(1,0,n-1,f,n-1,d))!=0)
        ans=min(ans,cur+g);
    }
    if(ans==(long)2e9+7) cout<<-1;
    else cout<<ans;
    return 0;
}