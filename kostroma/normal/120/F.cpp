#include<iostream>
#include<cstdio>
#include<string>
#include <queue>
#include <vector>
using namespace std;
typedef long long li;
typedef pair <int, int> pi;
#define mp make_pair
#define pb push_back
void solve ();
int ans=0;
int main()
{
		freopen("input.txt","r",stdin);
#ifndef _DEBUG
	freopen("output.txt","w",stdout);
#endif
	int t; cin>>t;
	while (t--)
	 solve();
	cout<<ans;
	return 0;
}
//#define int li
int n;
vector <int> e[200];
int d[200];
void bfs ( int v )
{
	d[v]=0;
	queue <int> q;
	q.push(v);
	while ( !q.empty() )
	{
		int cur=q.front();
		q.pop();
		for (int i=0; i<e[cur].size(); i++)
			if ( d[e[cur][i]]==-1 )
			{
				d[e[cur][i]]=d[cur]+1;
				q.push(e[cur][i]);
			}
	}
}
void solve()
{
	cin>>n;
	for (int i=0; i<n; i++)
		e[i].resize(0);
	for (int i=0; i<n-1; i++)
	{
		int q, w;
		 cin>>q>>w;
		 q--; w--;
		 e[q].pb (w);
		 e[w].pb(q);
	}
	int mx=0;
	for ( int i=0; i<n; i++ )
	{
		memset (d, -1, sizeof d);
		bfs (i);
		for (int j=0; j<n; j++)
			mx=max(mx, d[j]);
	}
	ans+=mx;
}