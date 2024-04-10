#include <iostream>
#include<algorithm>
#include<vector>
#define X first
#define Y second


using namespace std;

const int MAXN=300000;
typedef pair<bool,int>pii;
vector<int>v[MAXN*4];
int n,ans,a[MAXN];
vector<pii>ind[4*MAXN];

void make(int node,int l,int r)
{
    if(l+1>=r)
    {
        v[node].push_back(a[l]);
        return;
    }
    int mid=(l+r)/2;
    make(2*node,l,mid);
    make(2*node+1,mid,r);
    int p=0,q=0,sz=v[2*node].size(),sz1=v[2*node+1].size();
    while(p<sz || q<sz1)
    {
        if(p==sz)
        {
            v[node].push_back(v[2*node+1][q++]);
            ind[node].push_back(pii(1,q-1));
        }
        else if(q==sz1 || v[2*node][p]<v[2*node+1][q])
        {
            v[node].push_back(v[2*node][p++]);
            ind[node].push_back(pii(0,p-1));
        }
        else
        {
            v[node].push_back(v[2*node+1][q++]);
            ind[node].push_back(pii(1,q-1));
        }
    }
}

void f(int node,int l,int r,int beg,int en,int val,int p)
{
  //  cout<<l<<" "<<r<<" "<<beg<<" "<<en<<" "<<val<<" "<<p<<endl;
    if(p<0)
        return;
    if(beg<=l && r<=en)
    {
        ans+=p+1;
        return;
    }
    int x=ind[node][p].Y;
    int y=p-x-1;
    if(ind[node][p].X==1)
        swap(x,y);
    int mid=(l+r)/2;
    if(beg<mid) f(2*node,l,mid,beg,en,val,x);
    if(mid<en)  f(2*node+1,mid,r,beg,en,val,y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    make(1,0,n);
    for(int k=1;k<n;k++)
    {
        ans=0;
        for(int i=0;i*k+1<n;i++)
        {
            int l=i*k+1,r=min(n,k*(i+1)+1);
            int x=lower_bound(v[1].begin(),v[1].end(),a[i])-v[1].begin()-1;
            f(1,0,n,l,r,a[i],x);
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}