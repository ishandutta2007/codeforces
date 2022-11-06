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
		int n,m,q;
		cin>>n>>m>>q;
		string s[n];
		int f[n][m];
		FOR(i,0,n)
		cin>>s[i];
		set<pair<int,int> > ar,br;
		bool g;
		int cou=0;
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				g=0;
				if(i>0)
				g=(g||s[i-1][j]==s[i][j]);
				if(i<(n-1))
				g=g||(s[i+1][j]==s[i][j]);
				if(j>0)
				g=g||(s[i][j-1]==s[i][j]);
				if(j<(m-1))
				g=g||(s[i][j+1]==s[i][j]);
				if(g)
				{
					f[i][j]=0;
					ar.insert(mp(i,j));
					cou++;
				}
				else
				f[i][j]=-1;
			}
		}
		int i,j;
		ll ti;
		if(cou==0)
		{
			FOR(z,0,q)
			{
				cin>>i>>j>>ti;
				cout<<s[i-1][j-1]<<'\n';
			}
			return 0;
		}
		int u=1;
		pair<int,int> k;
		while(cou<(n*m))
		{
			if(u%2==1)
			{
				while(!ar.empty())
				{
					k=*ar.begin();
					ar.erase(k);
					i=k.first;
					j=k.second;
					if(i>0 && f[i-1][j]==-1)
					{
						f[i-1][j]=u;
						br.insert(mp(i-1,j));
						cou++;
					}
					if(i<(n-1) && f[i+1][j]==-1)
					{
						f[i+1][j]=u;
						br.insert(mp(i+1,j));
						cou++;
					}
					if(j>0 && f[i][j-1]==-1)
					{
						f[i][j-1]=u;
						br.insert(mp(i,j-1));
						cou++;
					}
					if(j<(m-1) && f[i][j+1]==-1)
					{
						f[i][j+1]=u;
						br.insert(mp(i,j+1));
						cou++;
					}
				}
			}
			else
			{
				while(!br.empty())
				{
					k=*br.begin();
					br.erase(k);
					i=k.first;
					j=k.second;
					if(i>0 && f[i-1][j]==-1)
					{
						f[i-1][j]=u;
						ar.insert(mp(i-1,j));
						cou++;
					}
					if(i<(n-1) && f[i+1][j]==-1)
					{
						f[i+1][j]=u;
						ar.insert(mp(i+1,j));
						cou++;
					}
					if(j>0 && f[i][j-1]==-1)
					{
						f[i][j-1]=u;
						ar.insert(mp(i,j-1));
						cou++;
					}
					if(j<(m-1) && f[i][j+1]==-1)
					{
						f[i][j+1]=u;
						ar.insert(mp(i,j+1));
						cou++;
					}
				}
			}
			u++;
		}
		
		FOR(z,0,q)
		{
			cin>>i>>j>>ti;
			ti-=f[i-1][j-1];
			if(ti<0 || ti%2==0)
			{
				cout<<s[i-1][j-1]<<'\n';
			}
			else
			{
				cout<<(1^(s[i-1][j-1]-'0'))<<'\n';
			}
		}
	}
	return 0;
}