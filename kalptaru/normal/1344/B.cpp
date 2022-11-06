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
//ll mod=998244353;
ll INF=1e18;
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
bool vis[1001][1001];
int n,m;
void dfs(int i,int j)
{
//	cout<<i<<' '<<j<<'\n';
	if(vis[i][j]==1)
	return;
	vis[i][j]=1;
	if(i<(n-1))
	dfs(i+1,j);
	if(i>0)
	dfs(i-1,j);
	if(j>0)
	dfs(i,j-1);
	if(j<(m-1))
	dfs(i,j+1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		cin>>n>>m;
		string s[n];
		FOR(i,0,n)
		cin>>s[i];
		int mic[m],mac[m],mir[n],mar[n];
		bool comr=0,comc=0;
		FOR(i,0,m)
		{
			mic[i]=n;
			mac[i]=-1;
		}
		FOR(i,0,n)
		{
			mir[i]=m;
			mar[i]=-1;
		}
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				if(s[i][j]=='#')
				{
					mic[j]=min(i,mic[j]);
					mac[j]=max(i,mac[j]);
					mir[i]=min(j,mir[i]);
					mar[i]=max(j,mar[i]);
				}
				else
				vis[i][j]=1;
			}
		}
		FOR(i,0,n)
		{
			if(mar[i]==-1)
			{
				comr=1;
				break;
			}
		}
		FOR(i,0,m)
		{
			if(mac[i]==-1)
			{
				comc=1;
				break;
			}
		}
//		cout<<comc<<' '<<comr<<'\n';
		if(comc!=comr)
		{
			cout<<"-1";
			return 0;
		}
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				if(s[i][j]=='.')
				{
					if(mic[j]<i && mac[j]>i)
					{
						cout<<"-1";
						return 0;
					}
					if(mir[i]<j && mar[i]>j)
					{
						cout<<"-1";
						return 0;
					}
				}
			}
		}
		int ans=0;
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				if(vis[i][j]==0)
				{
					ans++;
//					cout<<ans<<'k'<<'\n';
					dfs(i,j);
				}
			}
		}
		cout<<ans;
	}
	return 0;
}