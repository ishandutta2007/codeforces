#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5;
int n,par[maxn][21],last;
ll sum[maxn][21],MAX[maxn][21];

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  int q;
  cin>>q;
  n=1;
  while(q--)
    {
      ll type,v,x;
      cin>>type>>v>>x;
      v^=last;
      x^=last;
      if(type==1)
	{
	  //cerr<<v<<"_>"<<x<<endl;
	  n++;
	  for(int i=20;i>-1;i--)
	    if(MAX[v][i]<x)
	      v=par[v][i];
	  par[n][0]=v;
	  //cerr<<n<<" "<<v<<" "<<x<<endl;
	  sum[n][0]=x;
	  MAX[n][0]=x;
	  for(int i=1;i<=20;i++)
	    {
	      par[n][i]=par[par[n][i-1]][i-1];
	      MAX[n][i]=max(MAX[n][i-1],MAX[par[n][i-1]][i-1]);
	      sum[n][i]=sum[n][i-1]+sum[par[n][i-1]][i-1];
	    }
	}
      else
	{
	  last=0;
	  for(int i=20;i>-1;i--)
	    if(par[v][i]!=0 && sum[v][i]<=x)
	      {
		x-=sum[v][i];
		v=par[v][i];
		last+=(1<<i);
	      }
	  if(sum[v][0]<=x) last++;
	  cout<<last<<endl;
	}
    }
}