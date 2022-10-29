#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
double tree[400005],lazy[400005][2];
long n,q,a[100005],i,t;
void build(int node, int start, int end)
{
    if(start==end) tree[node]=a[start];
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
void update(int node, int start, int end, int l, int r, double m, double a)
{
    if(lazy[node][0]!=1 || lazy[node][1]!=0)
    {
        tree[node]=tree[node]*lazy[node][0]+(end-start+1)*lazy[node][1];
        if(start!=end)
        {
            lazy[node*2][0]*=lazy[node][0];
            lazy[node*2+1][0]*=lazy[node][0];
            lazy[node*2][1]=lazy[2*node][1]*lazy[node][0]+lazy[node][1];
            lazy[node*2+1][1]=lazy[2*node+1][1]*lazy[node][0]+lazy[node][1];
        }
        lazy[node][0]=1;
        lazy[node][1]=0;
    }
    if(start>end or start>r or end<l) return;
    if(start>=l and end<=r)
    {
        tree[node]=tree[node]*m+(end-start+1)*a;
        if(start != end)
        {
            lazy[node*2][0]*=m;
            lazy[node*2+1][0]*=m;
            lazy[node*2][1]=lazy[2*node][1]*m+a;
            lazy[node*2+1][1]=lazy[2*node+1][1]*m+a;
        }
        return;
    }
    int mid=(start+end)/2;
    update(node*2,start,mid,l,r,m,a);
    update(node*2+1,mid+1,end,l,r,m,a);
    tree[node]=tree[node*2]+tree[node*2+1];
}

double query(int node, int start, int end, int l, int r)
{
    if(start>end or start>r or end<l) return 0;
    if(lazy[node][0]!=1 || lazy[node][1]!=0)
    {
        tree[node]=tree[node]*lazy[node][0]+(end-start+1)*lazy[node][1];
        if(start != end)
        {
            lazy[node*2][0]*=lazy[node][0];
            lazy[node*2+1][0]*=lazy[node][0];
            lazy[node*2][1]=lazy[2*node][1]*lazy[node][0]+lazy[node][1];
            lazy[node*2+1][1]=lazy[2*node+1][1]*lazy[node][0]+lazy[node][1];
        }
        lazy[node][0]=1;
        lazy[node][1]=0;
    }
    if(start>=l and end<=r) return tree[node];
    int mid=(start+end)/2;
    double p1=query(node*2,start,mid,l,r);
    double p2=query(node*2+1,mid+1,end,l,r);
    return (p1+p2);
}
int main()
{
    io
    cout<<fixed<<setprecision(7);
    double l1,r1,l2,r2,m1,m2,a1,a2,l,r;
    for(i=0;i<=4e5;++i)
    lazy[i][0]=1;
    cin>>n>>q;
    for(i=0;i<n;++i)
    cin>>a[i];
    build(1,0,n);
    while(q--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>l1>>r1>>l2>>r2;
            m1=(r1-l1)/(r1-l1+1);
            m2=(r2-l2)/(r2-l2+1);
            a1=query(1,0,n,l2-1,r2-1)/((r1-l1+1)*(r2-l2+1));
            a2=query(1,0,n,l1-1,r1-1)/((r2-l2+1)*(r1-l1+1));
            update(1,0,n,l1-1,r1-1,m1,a1);
            update(1,0,n,l2-1,r2-1,m2,a2);
        }
        else
        {
            cin>>l>>r;
            cout<<query(1,0,n,l-1,r-1)<<"\n";
        }
    }
    return 0;
}