#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
typedef long long ll;

const int maxn=1e6+100;
int n,dis[maxn],ans[maxn],p[maxn];
ll sum0,sum1;
bool mark[maxn];
vector<int>G[maxn],vec[maxn];

void dfs(int v)
{
  mark[v]=true;
  if(dis[v]%2==0)
    sum0+=v;
  else
    sum1+=v;
  for(int i=0;i<G[v].size();i++)
    {
      int u=G[v][i];
      if(!mark[u])
	{
	  dis[u]=dis[v]+1;
	  dfs(u);
	}
    }
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  if(n%2==0)
    {
      cout<<"First"<<endl;
      cout.flush();
      for(int i=0;i<2*n;i++)
	cout<<i%n +1<<" ";
      cout<<endl;
      cout.flush();
    }
  else
    {
      cout<<"Second"<<endl;
      for(int i=1;i<=2*n;i++){
	if(i<=n)
	  G[i].push_back(i+n);
	else
	  G[i].push_back(i-n);
	cin>>p[i];
	vec[p[i]].push_back(i);
      }
      for(int i=1;i<=n;i++)
	{
	  G[vec[i][0]].push_back(vec[i][1]);
	  G[vec[i][1]].push_back(vec[i][0]);
	}
      for(int i=1;i<=2*n;i++)
	if(!mark[i])
	  dfs(i);
      for(int i=1;i<=2*n;i++)
	{
	  if(sum0%(2*n)==0 && dis[i]%2==0)
	    ans[p[i]]=i;
	  if(sum1%(2*n)==0 && dis[i]%2==1)
	    ans[p[i]]=i;
	}
      for(int i=1;i<=n;i++)
	cout<<ans[i]<<" ";
      cout<<endl;
      cout.flush();
    }
}