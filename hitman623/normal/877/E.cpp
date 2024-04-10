#include <bits/stdc++.h>
#define pb push_back
#define pll pair < int , int >
#define vll vector < pll >
#define ml map < int , int >
#define mll map < pll , int >
#define x first
#define y second
#define vl vector < int >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vl a[200005];
int st[200005],en[200005],cur=-1,t[200005];
int seg[800005],aa[200005],lazy[800005]={0};
int n,x,y,i,q,v;
void dfs(int node,int par)
{
    int i;
    st[node]=++cur;
    aa[st[node]]=t[node];
    for(i=0;i<a[node].size();++i)
    if(a[node][i]!=par)
    dfs(a[node][i],node);
    en[node]=cur;
}

void build(int node , int start , int end)
{
    int mid,m;
    if(start==end) seg[node]=aa[start];
    else
    {
        mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        seg[node]=seg[2*node]+seg[2*node+1];
    }
}

void update(int node, int start, int end, int l, int r)
{
    if(lazy[node])
    {
        seg[node]=end-start+1-seg[node];
        if(start!=end)
        {
            lazy[node*2]=!lazy[node*2];
            lazy[node*2+1]=!lazy[node*2+1];
        }
        lazy[node]=0;
    }
    if(start>end or start>r or end<l) return;
    if(start>=l and end<=r)
    {
        seg[node]=end-start+1-seg[node];
        if(start!=end)
        {
            lazy[node*2]=!lazy[node*2];
            lazy[node*2+1]=!lazy[node*2+1];
        }
        return;
    }
    int mid=(start+end)/2;
    update(node*2,start,mid,l,r);
    update(node*2+1,mid+1,end,l,r);
    seg[node]=seg[node*2]+seg[node*2+1];
}

int query(int node,int start,int end,int l,int r)
{
    int mid,p1,p2,m;
    if(l>end || r<start || start>end) return 0;
    if(lazy[node])
    {
        seg[node]=end-start+1-seg[node];
        if(start!=end)
        {
            lazy[node*2]=!lazy[node*2];
            lazy[node*2+1]=!lazy[node*2+1];
        }
        lazy[node]=0;
    }
    if(start>=l && end<=r) return seg[node];
    else
    {
        mid=(start+end)/2;
        p1=query(2*node,start,mid,l,r);
        p2=query(2*node+1,mid+1,end,l,r);
        return p1+p2;
    }
}
signed main()
{
    io
    cin>>n;
    for(i=2;i<=n;++i)
    {
        cin>>x;
        a[i].pb(x);
        a[x].pb(i);
    }
    for(i=1;i<=n;++i)
    cin>>t[i];
    dfs(1,-1);
    build(1,0,n-1);
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s>>v;
        if(s=="get")
        cout<<query(1,0,n-1,st[v],en[v])<<"\n";
        else
        update(1,0,n-1,st[v],en[v]);
    }
    return 0;
}