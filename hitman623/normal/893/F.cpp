#include <bits/stdc++.h>
#define pb push_back
#define vl vector < int >
#define pll pair < int , int >
#define vll vector < pll >
#define x first
#define y second
#define ml map < int , int >
#define mll map < pll , int >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
vl a[100005];
int hell=1000000007,st[100005],en[100005],cur=0,d[100005],val[100005],v[100005];
pll t[20][100005];
void dfs(int node,int par,int l)
{
    int i;
    st[node]=++cur;
    d[st[node]]=l;
    for(i=0;i<a[node].size();++i)
    if(a[node][i]!=par)
    dfs(a[node][i],node,l+1);
    en[node]=cur;
}
void build(int c,int l,int r)
{
    if(l==r) t[c][l]={d[l],val[l]};
    else
    {
        int mid=(l+r)/2;
        build(c+1,l,mid);
        build(c+1,mid+1,r);
        int i=l,j=mid+1,k=l;
        while(i<=mid && j<=r)
        {
            if(t[c+1][i].x<t[c+1][j].x)
            t[c][k++]=t[c+1][i++];
            else t[c][k++]=t[c+1][j++];
        }
        while(i<=mid)
        t[c][k++]=t[c+1][i++];
        while(j<=r)
        t[c][k++]=t[c+1][j++];
        for(i=l+1;i<=r;++i)
        t[c][i].y=min(t[c][i].y,t[c][i-1].y);
    }
}
int query(int c,int l,int r,int l1,int r1,int k)
{
    if(r1<l || l1>r) return hell;
    if(l>=l1 && r<=r1)
    {
        pll temp={k,hell};
        int w=upper_bound(t[c]+l,t[c]+r+1,temp)-t[c];
        if(w==l) return hell;
        return t[c][w-1].y;
    }
    else
    {
        int mid=(l+r)/2;
        return min(query(c+1,l,mid,l1,r1,k),query(c+1,mid+1,r,l1,r1,k));
    }
}
int main()
{
    io
    int n,r,i,x,y,m,p,q,k;
    cin>>n>>r;
    for(i=1;i<=n;++i)
    cin>>v[i];
    for(i=0;i<n-1;++i)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(r,-1,0);
    for(i=1;i<=n;++i)
    val[st[i]]=v[i];
    build(1,1,cur);
    cin>>m;
    int last=0;
    while(m--)
    {
        cin>>p>>q;
        x=(last+p)%n+1;
        k=(last+q)%n;
        last=query(1,1,cur,st[x],en[x],k+d[st[x]]);
        cout<<last<<"\n";
    }
    return 0;
}