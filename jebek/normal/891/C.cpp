#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6;
int q,n,m,par[3*maxn],fr[maxn],to[maxn],c[maxn],e[maxn],cnt,f[3*maxn],fr1[maxn],to1[maxn];
vector<int>vec;

bool cmp(int i,int j)
{
  return c[i]<c[j];
}

int findpar(int v)
{
  if(par[v]==v) return v;
  return par[v]=findpar(par[v]);
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    par[i]=i;
  for(int i=0;i<m;i++)
    {
      cin>>fr[i]>>to[i]>>c[i];
      e[i]=i;
    }
  sort(e,e+m,cmp);
  cnt=n+1;
  for(int i=0;i<m;)
    {
      vec.clear();
      int w=c[e[i]];
      for(int j=i;j<m && c[e[j]]==w;j++)
	{
	  int v=fr[e[j]],u=to[e[j]];
	  v=findpar(v);
	  u=findpar(u);
	  if(!f[v])
	    f[v]=cnt++,vec.push_back(v);
	  if(!f[u])
	    f[u]=cnt++,vec.push_back(u);
	  fr1[e[j]]=f[v];
	  to1[e[j]]=f[u];
	}
      for(int j=i;j<m && c[e[j]]==w;j++,i++)
	{
	  int v=fr[e[j]],u=to[e[j]];
	  v=findpar(v);
	  u=findpar(u);
	  if(v!=u)
	    par[v]=u;
	}
      for(int j=0;j<vec.size();j++)
	f[vec[j]]=0;
    }
  cin>>q;
  for(int i=0;i<=cnt;i++)
    par[i]=i;
  while(q--)
    {
      vec.clear();
      int t;
      cin>>t;
      bool yes=true;
      for(int i=0;i<t;i++)
	{
	  int ind;
	  cin>>ind;
	  ind--;
	  int v=fr1[ind],u=to1[ind];
	  //cout<<v<<"****"<<u<<endl;
	  v=findpar(v),u=findpar(u);
	  if(v==u) yes=false;
	  else par[v]=u,vec.push_back(v);
	}
      if(yes) cout<<"YES\n";
      else cout<<"NO\n";
      for(int i=0;i<vec.size();i++)
	par[vec[i]]=vec[i];
    }
}