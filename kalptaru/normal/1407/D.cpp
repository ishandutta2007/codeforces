#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
// ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
//			re%=mod;
		}
		a=(a*a);
//		a%=mod;
		b>>=1;
	}
	return re;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1;
	// cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll h[n];
		int dp[n];
		FOR(i,0,n)
		{
			dp[i]=-1;
		}
		stack<ll> sm,gr;
		cin>>h[0];
		sm.push(0);
		gr.push(0);
		vector<int> gra[n];
		FOR(i,1,n)
		{
			cin>>h[i];
			while(gr.size()>0 && h[i]>h[gr.top()])
			{
				gra[gr.top()].push_back(i);
				// gra[i].push_back(gr.top());
				gr.pop();
			}
			if(gr.size()>0)
			{
				gra[gr.top()].push_back(i);
				if(h[gr.top()]==h[i])
					gr.pop();
			}
			gr.push(i);
			while(sm.size()>0 && h[i]<h[sm.top()])
			{
				gra[sm.top()].push_back(i);
				// gra[i].push_back(sm.top());
				sm.pop();
			}
			if(sm.size()>0)
			{
				gra[sm.top()].push_back(i);
				if(h[sm.top()]==h[i])
					sm.pop();
			}
			sm.push(i);
		}
		dp[0]=0;
		queue<int> bfs;
		bfs.push(0);
		while(!bfs.empty())
		{
			int no=bfs.front();
			bfs.pop();
			FOR(j,0,gra[no].size())
			{
				if(dp[gra[no][j]]==-1)
				{
					dp[gra[no][j]]=dp[no]+1;
					bfs.push(gra[no][j]);
				}
			}
		}
		// FOR(i,0,n)
		// {
		// 	FOR(j,0,gra[i].size())
		// 	cout<<gra[i][j]<<' ';
		// 	cout<<'\n';
		// 	cout<<dp[i]<<'\n';
		// }
		cout<<dp[n-1];
	}
	return 0;
}