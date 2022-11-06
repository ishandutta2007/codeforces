#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod1=1000000007;
ll mod2=67280421310721;
ll INF=1e18;
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		int next[n]={-1};
		int ans[n]={0};
		int ans2[n]={0};
		vector<int> graph[n];
		int u,v;
		FOR(i,0,m)
		{
			cin>>u>>v;
			graph[v-1].pb(u-1);
		}
		int k;
		cin>>k;
		int p[k];
		FOR(i,0,k)
		{
			cin>>p[i];
			if(i>0)
			{
				next[p[i-1]-1]=p[i]-1;
			}
		}
		int s=p[k-1]-1; 
		queue<int> q;
		bool used[n]={0};
		int d[n]={0};
		q.push(s);
		used[s] = true;
//		cout<<'o';
		while (!q.empty()) {
		    int v = q.front();
		    q.pop();
		    for (int w=0; w<graph[v].size(); w++) 
			{
		    	int u=graph[v][w];
//		    	cout<<v<<' '<<u<<'\n';
		        if (!used[u]) {
		            used[u] = true;
		            q.push(u);
		            d[u]=d[v]+1;
		        	if(v==next[u])
		        	{
		        		ans[u]=1;
//		        		cout<<u<<"k ";
					}
		        }
		        else if(d[u]==(d[v]+1))
		        {
		        	if(v==next[u])
		        	{
		        		ans[u]=1;
					}
		        	ans2[u]=1;
				}
		    }
		}
//		cout<<'k';
		int mi=0,ma=0;
		FOR(i,0,k-1)
		{
			if(ans[p[i]-1]==1)
			{
				if(ans2[p[i]-1]==1)
				ma++;
			}
			else
			{
//				cout<<p[i];
				mi++;
				ma++;
			}
		}
		cout<<mi<<' '<<ma;
	}
	return 0;
}