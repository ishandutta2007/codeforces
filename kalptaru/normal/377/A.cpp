#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int k;
void dfs(int u,int v,string s[],int n,int m)
{
	if(k==0)
	return;
	s[u][v]='X';
	k--;
	if(u>0)
	{
		if(s[u-1][v]=='.')dfs(u-1,v,s,n,m);
	}
	if(u<n-1)
	{
		if(s[u+1][v]=='.')dfs(u+1,v,s,n,m);
	}
	if(v>0)
	{
		if(s[u][v-1]=='.')dfs(u,v-1,s,n,m);
	}
	if(v<m-1)
	{
		if(s[u][v+1]=='.')dfs(u,v+1,s,n,m);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while(t--)
	{
		int n,m,r=0;
		cin>>n>>m>>k;
		string s[n];
		int u,v;
		FOR(i,0,n)
		{
			cin>>s[i];
			FOR(j,0,m)
			{
				if(s[i][j]=='.')
				{
					u=i;
					v=j;
					r++;
				}
			}
		}
		k=r-k;
		dfs(u,v,s,n,m);
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				if(s[i][j]=='X')
				cout<<'.';
				else if(s[i][j]=='.')
				cout<<'X';
				else
				cout<<'#';
				
			}
			cout<<'\n';
		}
		
	}
	return 0;
}