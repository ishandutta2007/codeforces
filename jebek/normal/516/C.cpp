#include <iostream>
#include<algorithm>

using namespace std;

const int MAXN=200000;
long long n,m,ans,ans1,d[MAXN],h[MAXN],MAX1[4*MAXN],MAX2[4*MAXN],MAX[4*MAXN],sum[4*MAXN];

void make(int node,int l,int r)
{
    if(l+1>=r)
    {
        sum[node]=d[l];
        MAX[node]=0;
        MAX1[node]=2*h[l]+d[l];
        MAX2[node]=2*h[l];
   // cout<<l<<" "<<r<<" "<<MAX[node]<<" "<<MAX1[node]<<" "<<MAX2[node]<<" "<<sum[node]<<endl;
        return;
    }
    int mid=(l+r)/2;
    make(2*node,l,mid);
    make(2*node+1,mid,r);
    MAX[node]=max(max(MAX[2*node],MAX[2*node+1]),MAX1[2*node]+MAX2[2*node+1]);
    MAX1[node]=max(MAX1[2*node+1],MAX1[2*node]+sum[2*node+1]);
    MAX2[node]=max(MAX2[2*node],MAX2[2*node+1]+sum[2*node]);
    sum[node]=sum[2*node]+sum[2*node+1];
  //  cout<<l<<" "<<r<<" "<<MAX[node]<<" "<<MAX1[node]<<" "<<MAX2[node]<<" "<<sum[node]<<endl;
}

void f(int node,int l,int r,int beg,int en)
{
    if(beg<=l && r<=en)
    {
        ans=max(ans,MAX[node]);
        ans=max(ans,ans1+MAX2[node]);
        ans1=max(ans1+sum[node],MAX1[node]);
        return;
    }
    int mid=(l+r)/2;
    if(beg<mid) f(2*node,l,mid,beg,en);
    if(mid<en)  f(2*node+1,mid,r,beg,en);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>d[i];
        d[i+n]=d[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
        h[i+n]=h[i];
    }
    make(1,1,2*n);
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        ans=ans1=-100000000000000;
        if(l<=r)
            f(1,1,2*n,r,l+n-1);
        else
            f(1,1,2*n,r,l-1);
        cout<<ans<<endl;
    }
}