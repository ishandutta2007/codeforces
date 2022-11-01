#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN=300000;
int n,q,p[MAXN],h[MAXN],ans,MAX[MAXN*4],MAX1;
vector<int>v1[4*MAXN],v[MAXN*4],sum[4*MAXN];

void make(int node,int l,int r)
{
    if(l+1>=r)
    {
        if(l<n-1 && p[l]+h[l]<p[l+1])
        {
            v[node].push_back(p[l]+h[l]);
            v1[node].push_back(p[l+1]);
            sum[node].push_back(p[l+1]-p[l]-h[l]);
        }
        MAX[node]=p[l]+h[l];
        return;
    }
    int mid=(l+r)/2;
    make(2*node,l,mid);
    make(2*node+1,mid,r);
    v1[node]=v1[2*node];
    v[node]=v[2*node];
    sum[node]=sum[2*node];
    MAX[node]=max(MAX[2*node],MAX[2*node+1]);
    for(int j=0;j<v[2*node+1].size();j++)
    {
        if(v1[2*node+1][j]<=MAX[2*node])
            continue;
        v[node].push_back(max(MAX[2*node],v[2*node+1][j]));
        v1[node].push_back(v1[2*node+1][j]);
        int sz=sum[node].size();
        sum[node].push_back(v1[node].back()-v[node].back()+(sz==0?0:sum[node][sz-1]));
    }
}

void f(int node,int l,int r,int beg,int en)
{
    if(beg<=l && r<=en)
    {
       // cout<<l<<" "<<r<<" "<<MAX1<<" "<<ans<<endl;
        if(sum[node].size()){
          //  cout<<sum[node].back()<<endl;
            int k=upper_bound(v1[node].begin(),v1[node].end(),MAX1)-v1[node].begin();
            ans+=sum[node].back();
            if(k>0)
                ans-=sum[node][k-1];
         //   cout<<ans<<"*"<<endl;
            if(k<v1[node].size() && MAX1>v[node][k])
                ans-=MAX1-v[node][k];
        }
        MAX1=max(MAX1,MAX[node]);
        return;
    }
    int mid=(l+r)/2;
    if(beg<mid) f(2*node,l,mid,beg,en);
    if(mid<en)  f(2*node+1,mid,r,beg,en);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i]>>h[i];
    make(1,0,n);
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        ans=0;
        MAX1=0;
        f(1,0,n,l-1,r-1);
        cout<<ans<<endl;
    }
}