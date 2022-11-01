#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int maxn=1e5+100;
int n,m,a[maxn],b[maxn],c[maxn],ans;
set<pii>s[maxn];

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m;
  for(int i=0;i<m;i++)
    cin>>a[i]>>b[i]>>c[i];
  for(int q=m-1;q>-1;q--)
    {
      int v=a[q],u=b[q],w=c[q];
      set<pii>::iterator it=s[u].lower_bound(pii(w+1,-1));
      int dp=1;
      if(it!=s[u].end())
	dp=(it->second)+1;
      ans=max(ans,dp);
      it=s[v].lower_bound(pii(w+1,-1));
      if(it==s[v].end() || (it->second) < dp)
	{
	  s[v].insert(pii(w,dp));
	  it=s[v].find(pii(w,dp));
	  if(it!=s[v].begin())
	    {
	      it--;
	      set<pii>::iterator tmp;
	      while(it!=s[v].begin() && (it->second) <= dp)
		{
		  tmp = it;
		  it--;
		  s[v].erase(tmp);
		}
	      if((it->second) <= dp)
		s[v].erase(it);
	    }
	}
    }
  cout<<ans<<endl;
}