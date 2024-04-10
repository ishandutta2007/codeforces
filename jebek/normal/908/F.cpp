#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
ll ans;
int n,p[2];
vector<ll>v[3];

int f(char c)
{
  if(c=='R') return 0;
  if(c=='B') return 1;
  return 2;
}

void solve(int x,int y)
{
  ll MIN=1000000000;
  ll MAX=0;
  for(int i=0;i<v[x].size();i++)
    {
      MAX=max(MAX,v[x][i]);
      MIN=min(MIN,v[x][i]);
    }
  for(int i=0;i<v[y].size();i++)
    {
      MAX=max(MAX,v[y][i]);
      MIN=min(MIN,v[y][i]);
    }
  if(MAX>MIN) ans+=MAX-MIN;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)
    {
      int tmp;char c;
      cin>>tmp>>c;
      v[f(c)].push_back(tmp);
    }
  solve(0,2);
  solve(1,2);
  if(v[2].size()>0)
    {
      for(int i=0;i<2;i++)
	while(p[i]<v[i].size() && v[i][p[i]]<v[2][0])
	  p[i]++;
      for(int i=1;i<v[2].size();i++)
	{
	  ll sum=v[2][i]-v[2][i-1];
	  for(int j=0;j<2;j++)
	    {
	      ll last=v[2][i-1],MAX=0;
	      while(p[j]<v[j].size() && v[j][p[j]]<v[2][i])
		{
		  MAX=max(MAX,v[j][p[j]]-last);
		  last=v[j][p[j]];
		  p[j]++;
		}
	      MAX=max(MAX,v[2][i]-last);
	      sum-=MAX;
	    }
	  if(sum<0) ans+=sum;
	}
    }
  cout<<ans<<endl;
}