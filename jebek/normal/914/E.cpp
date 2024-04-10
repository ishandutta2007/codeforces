#include<bits/stdc++.h>
using namespace std;

const int maxx=(1<<21)+100,maxn=2e5+100;
bool mark[maxn];
int n,a[maxn],pat[maxn],par[maxn],siz[maxn],MAX[maxn];
vector<int>G[maxn],child[maxn];
long long dp[maxn],t1[maxx];
int t[maxx];

void dfs2(int v)
{
  for(int i=0;i<child[v].size();i++)
    {
      int u=child[v][i];
      dfs2(u);
      dp[v]+=dp[u];
    }
}

int count(int x)
{
  int ret=t[x];
  t1[x]++;
  for(int i=0;i<20;i++){
    ret+=t[x^(1<<i)];
    t1[x^(1<<i)]++;
  }
  return ret;
}

void add(int v)
{
  t[pat[v]]++;
  dp[v]-=t1[pat[v]];
  //cerr<<v<<"-"<<t1[pat[v]]<<endl;
  for(int i=0;i<child[v].size();i++)
    add(child[v][i]);
}

void check(int v,int w)
{
  int tmp=count(pat[v]^(1<<a[w]));
  dp[par[w]]-=tmp;
  dp[w]-=tmp;
  dp[v]+=tmp;
  // cerr<<v<<"+"<<tmp<<endl;
  //cerr<<par[w]<<"-"<<tmp<<endl;
  //cerr<<w<<"-"<<tmp<<endl;
  for(int i=0;i<child[v].size();i++)
    check(child[v][i],w);
}

void clean(int v)
{
  t[pat[v]]--;
  dp[v]+=t1[pat[v]];
  //cerr<<v<<"+"<<t1[pat[v]]<<endl;
  if(t[pat[v]]==0) t1[pat[v]]=0;
  for(int i=0;i<child[v].size();i++)
    clean(child[v][i]);
}

void solve(int v)
{
  //cout<<"########"<<v<<endl;
  if(child[v].size()>0)
    {
      for(int i=0;i<child[v].size();i++)
	{
	  int u=child[v][i];
	  if(u!=MAX[v])
	    {
	      solve(u);
	      clean(u);
	    } 
	}
      solve(MAX[v]);
      for(int i=0;i<child[v].size();i++)
	{
	  int u=child[v][i];
	  if(u!=MAX[v])
	    {
	      check(u,v);
	      add(u);
	    }
	}
    }
  t[pat[v]]++;
  dp[v]-=t1[pat[v]];
  //cerr<<v<<"-"<<t1[pat[v]]<<endl;
  int tmp=dp[par[v]];
  dp[par[v]]-=count(pat[par[v]]);
  //cerr<<par[v]<<"-"<<tmp-dp[par[v]]<<endl;
  //cerr<<"$$$$$$"<<endl;
}

void dfs(int v,int x)
{
  mark[v]=true;
  x^=(1<<a[v]);
  pat[v]=x;
  for(int i=0;i<G[v].size();i++)
    {
      int u=G[v][i];
      if(!mark[u]){
	par[u]=v;
	dfs(u,x);
	siz[v]+=siz[u];
	child[v].push_back(u);
	if(MAX[v]==0 || siz[MAX[v]]<siz[u])
	  MAX[v]=u;
      }
    }
  siz[v]++;
}
      
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(int i=1;i<n;i++)
    {
      int v,u;
      cin>>v>>u;
      G[v].push_back(u);
      G[u].push_back(v);
    }
  for(int i=1;i<=n;i++)
    {
      char c;
      cin>>c;
      a[i]=int(c-'a');
    }
  dfs(1,0);
  
  solve(1);
  clean(1);
  
  dfs2(1);
  for(int i=1;i<=n;i++)
    cout<<dp[i]<<' ';
}