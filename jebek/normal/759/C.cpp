#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5;
int MAX[4*maxn],flag[4*maxn],n,a[maxn];

void update(int x)
{
  flag[2*x]+=flag[x];
  flag[2*x+1]+=flag[x];
  MAX[2*x]+=flag[x];
  MAX[2*x+1]+=flag[x];
  flag[x]=0;
}

void add(int node,int l,int r,int beg,int en,int val)
{
  if(beg<=l && r<=en)
    {
      flag[node]+=val;
      MAX[node]+=val;
      return;
    }
  update(node);
  int mid=(l+r)/2;
  if(beg<mid) add(2*node,l,mid,beg,en,val);
  if(mid<en) add(2*node+1,mid,r,beg,en,val);
  MAX[node]=max(MAX[2*node],MAX[2*node+1]);
}

void f(int node,int l,int r)
{
  //cout<<node<<" "<<l<<" "<<r<<" "<<MAX
  if(l+1>=r)
    {
      if(MAX[node]>0)
	cout<<a[l]<<'\n';
      else
	cout<<"-1\n";
      return;
    }
  update(node);
  int mid=(l+r)/2;
  if(MAX[2*node+1]>0) f(2*node+1,mid,r);
  else f(2*node,l,mid);
}
      

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)
    {
      int x,y,z;
      cin>>x>>y;
      if(y==0)
	{
	  add(1,0,n,0,x,-1);
	}
      else
	{
	  cin>>z;
	  a[x-1]=z;
	  add(1,0,n,0,x,1);
	}
      f(1,0,n);
    }
}