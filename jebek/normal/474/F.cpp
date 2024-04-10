#include <iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAXN=1000000;
long long MIN[MAXN],f[MAXN],MIN1,t1,g,t[MAXN],n,q,a[MAXN];

void make(int node,int l,int r)
{
    if(l+1>=r)
    {
        MIN[node]=a[l];
        t[node]=1;
        f[node]=a[l];
        return;
    }
    int mid=(l+r)/2;
    make(2*node,l,mid);
    make(2*node+1,mid,r);
    f[node]=__gcd(f[2*node],f[2*node+1]);
    MIN[node]=min(MIN[2*node],MIN[2*node+1]);
    if(MIN[node*2]==MIN[node])  t[node]+=t[2*node];
    if(MIN[node*2+1]==MIN[node])  t[node]+=t[2*node+1];
}

void f1(int node,int l,int r,int beg,int en)
{
    if(beg<=l && r<=en)
    {
        if(MIN[node]==MIN1)
            t1+=t[node];
        else if(MIN[node]<MIN1)
        {
            MIN1=MIN[node];
            t1=t[node];
        }
        return;
    }
    int mid=(l+r)/2;
    if(beg<mid) f1(2*node,l,mid,beg,min(mid,en));
    if(mid<en)  f1(2*node+1,mid,r,max(mid,beg),en);
}

void f2(int node,int l,int r,int beg,int en)
{
    if(beg<=l && r<=en)
    {
        g=__gcd(g,f[node]);
        return;
    }
    int mid=(l+r)/2;
    if(beg<mid) f2(2*node,l,mid,beg,min(mid,en));
    if(mid<en)  f2(2*node+1,mid,r,max(mid,beg),en);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    make(1,0,n);
    cin>>q;
    for(int i=0;i<q;i++)
    {
        MIN1=2000000000;
        t1=0;
        int c,b;
        cin>>c>>b;
        f1(1,0,n,c-1,b);
        g=MIN1;
        f2(1,0,n,c-1,b);
       // cout<<c<<" "<<b<<" "<<MIN1<<" "<<g<<" "<<t1<<endl;
        if(g==MIN1)
            cout<<b-c+1-t1<<endl;
        else
            cout<<b-c+1<<endl;
    }
}