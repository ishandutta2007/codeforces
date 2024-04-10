#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
struct tri
{
	int i,j,k;
};
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
ll mv[201][201][201];
bool inq[201][201][201];
ll lr[201],lg[201],lb[201];
queue<tri> bfs;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		ll r,g,b;
		cin>>r>>g>>b;
		FOR(i,0,r)
		cin>>lr[i];
		FOR(i,0,g)
		cin>>lg[i];
		FOR(i,0,b)
		cin>>lb[i];
		sort(lr,lr+r,greater<ll>());
		sort(lg,lg+g,greater<ll>());
		sort(lb,lb+b,greater<ll>());
		tri a,o;
		a.i=0;
		a.j=0;
		a.k=0;
		bfs.push(a);
		ll ans=0;
		int i,j,k;
		while(!bfs.empty())
		{
			a=bfs.front();
			bfs.pop();
			i=a.i;
			j=a.j;
			k=a.k;
//			cout<<i<<' '<<j<<' '<<k<<'\n';
			ans=max(ans,mv[i][j][k]);
			if(a.i<r && a.j<g)
			{
				if(inq[i+1][j+1][k]==0)
				{
					mv[i+1][j+1][k]=lr[i]*lg[j]+mv[i][j][k];
					inq[i+1][j+1][k]=1;
					o=a;
					o.i++;
					o.j++;
					bfs.push(o);
				}
				else
				{
					mv[i+1][j+1][k]=max(mv[i+1][j+1][k],lr[i]*lg[j]+mv[i][j][k]);
				}
			}
			if(a.i<r && a.k<b)
			{
				if(inq[i+1][j][k+1]==0)
				{
					mv[i+1][j][k+1]=lr[i]*lb[k]+mv[i][j][k];
					inq[i+1][j][k+1]=1;
					o=a;
					o.i++;
					o.k++;
					bfs.push(o);
				}
				else
				{
					mv[i+1][j][k+1]=max(mv[i+1][j][k+1],lr[i]*lb[k]+mv[i][j][k]);
				}
			}
			if(a.k<b && a.j<g)
			{
				if(inq[i][j+1][k+1]==0)
				{
					mv[i][j+1][k+1]=lb[k]*lg[j]+mv[i][j][k];
					inq[i][j+1][k+1]=1;
					o=a;
					o.k++;
					o.j++;
					bfs.push(o);
				}
				else
				{
					mv[i][j+1][k+1]=max(mv[i][j+1][k+1],lb[k]*lg[j]+mv[i][j][k]);
				}
			}
		}
		cout<<ans;
	}
	return 0;
}