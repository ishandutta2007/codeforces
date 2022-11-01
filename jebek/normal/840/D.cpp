#include<bits/stdc++.h>
using namespace std;

const int maxn=3e5+1000;
int n,q,ans,a[maxn];
vector<int>vec[4*maxn],v[maxn];

int num(int x,int l,int r)
{
  int l1=lower_bound(v[x].begin(),v[x].end(),l)-v[x].begin();
  int r1=lower_bound(v[x].begin(),v[x].end(),r)-v[x].begin();
  return r1-l1;
}

void make(int node,int l,int r)
{
  // cout<<node<<" "<<l<<" "<<r<<endl;
  if(l+1>=r)
    {
      vec[node].push_back(a[l]);
      return;
    }
  int mid=(l+r)/2;
  make(2*node,l,mid);
  make(2*node+1,mid,r);
  for(int i=2*node;i<2*node+2;i++)
    for(int j=0;j<vec[i].size();j++)
      if(num(vec[i][j],l,r)>(r-l)/5)
	vec[node].push_back(vec[i][j]);
  sort(vec[node].begin(),vec[node].end());
  vec[node].resize(unique(vec[node].begin(),vec[node].end())-vec[node].begin());
}

void f(int node,int l,int r,int beg,int en,int val)
{
  if(beg<=l && r<=en)
    {
      for(int i=0;i<vec[node].size();i++)
	if(num(vec[node][i],beg,en)>(en-beg)/val)
	  {
	    // cout<<vec[node][i]<<" "<<(beg-en)/val<<" "<<num(vec[node][i],beg,en)<<endl;
	    if(ans==-1) ans=vec[node][i];
	    else ans=min(ans,vec[node][i]);
	  }
      return;
    }
  int mid=(l+r)/2;
  if(beg<mid) f(2*node,l,mid,beg,en,val);
  if(mid<en) f(2*node+1,mid,r,beg,en,val);
}
  
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>q;
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
      v[a[i]].push_back(i);
    }
  make(1,0,n);
  for(int i=0;i<q;i++)
    {
      int l,r,k;
      cin>>l>>r>>k;
      l--;
      ans=-1;
      f(1,0,n,l,r,k);
      cout<<ans<<'\n';
    }
}