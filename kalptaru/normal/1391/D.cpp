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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		string s[n];
		FOR(i,0,n)
		cin>>s[i];
		int ans=0;
		if(min(n,m)>3)
		{
			cout<<-1;
			return 0;
		}
		if(min(n,m)==1)
		{
			cout<<0;
			return 0;
		}
		if(n<4)
		{
			if(n==2)
			{
				int o=0;
				FOR(i,0,m)
				{
					if((i%2)==0)
					{
						if(s[0][i]==s[1][i])
						o++;
					}
					else
					{
						if(s[0][i]!=s[1][i])
						o++;						
					}
				}
				cout<<min(o,m-o);
				return 0;
			}
			
				int a,b,c,d;
				a=b=c=d=m;
				FOR(i,0,m)
				{
					if((i%2)==0)
					{
						if(s[0][i]==s[1][i])
						{
							if(s[1][i]==s[2][i])
							{
								a--;
							}
							else
							{
								c--;
							}
						}
						else
						{
							if(s[1][i]==s[2][i])
							{
								d--;
							}
							else
							{
								b--;
							}
						}
					}
					else
					{
						if(s[0][i]==s[1][i])
						{
							if(s[1][i]==s[2][i])
							{
								b--;
							}
							else
							{
								d--;
							}
						}
						else
						{
							if(s[1][i]==s[2][i])
							{
								c--;
							}
							else
							{
								a--;
							}
						}						
					}
				}
				cout<<min(min(a,b),min(c,d));
				return 0;
		}
		else
		{
			if(m==2)
			{
				int o=0;
				FOR(i,0,n)
				{
					if((i%2)==0)
					{
						if(s[i][0]==s[i][0])
						o++;
					}
					else
					{
						if(s[i][0]!=s[i][1])
						o++;						
					}
				}
				cout<<min(o,n-o);
				return 0;
			}
			
				int a,b,c,d;
				a=b=c=d=n;
				FOR(i,0,n)
				{
					if((i%2)==0)
					{
						if(s[i][0]==s[i][1])
						{
							if(s[i][1]==s[i][2])
							{
								a--;
							}
							else
							{
								c--;
							}
						}
						else
						{
							if(s[i][1]==s[i][2])
							{
								d--;
							}
							else
							{
								b--;
							}
						}
					}
					else
					{
						if(s[i][0]==s[i][1])
						{
							if(s[i][1]==s[i][2])
							{
								b--;
							}
							else
							{
								d--;
							}
						}
						else
						{
							if(s[i][1]==s[i][2])
							{
								c--;
							}
							else
							{
								a--;
							}
						}						
					}
				}
				cout<<min(min(a,b),min(c,d));
				return 0;
		}		
	}
	return 0;
}