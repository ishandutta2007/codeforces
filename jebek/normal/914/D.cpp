#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+1000;
int g[maxn*4],a[maxn],n,q;

void make(int node,int l,int r)
{
  if(l+1>=r)
    {
      g[node]=a[l];
      return;
    }
  int mid=(l+r)/2;
  make(2*node,l,mid);
  make(2*node+1,mid,r);
  g[node]=__gcd(g[2*node],g[2*node+1]);
}

void change(int node,int l,int r,int x,int val)
{
  if(l+1>=r)
    {
      g[node]=val;
      return;
    }
  int mid=(l+r)/2;
  if(x<mid) change(2*node,l,mid,x,val);
  else change(2*node+1,mid,r,x,val);
  g[node]=__gcd(g[2*node],g[2*node+1]);
}

int numb(int node,int l,int r,int beg,int en,int val)
{
  if(beg<=l && r<=en)
    {
      if(g[node]%val==0) return 0;
      if(l+1>=r) return 1;
      if(g[2*node]%val!=0 && g[2*node+1]%val!=0) return 2;
      int mid=(l+r)/2;
      if(g[2*node]%val!=0) return numb(2*node,l,mid,beg,en,val);
      return numb(2*node+1,mid,r,beg,en,val);
    }
  else
    {
      int mid=(l+r)/2;
      int ret=0;
      if(beg<mid) ret+=numb(2*node,l,mid,beg,en,val);
      if(mid<en) ret+=numb(2*node+1,mid,r,beg,en,val);
      return ret;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  make(1,0,n);
  cin>>q;
  while(q--)
    {
      int type;
      cin>>type;
      if(type==1)
	{
	  int l,r,x;
	  cin>>l>>r>>x;
	  if(numb(1,0,n,l-1,r,x)<=1)
	    cout<<"YES\n";
	  else
	    cout<<"NO\n";
	}
      else
	{
	  int ind,x;
	  cin>>ind>>x;
	  change(1,0,n,ind-1,x);
	}
    }
}