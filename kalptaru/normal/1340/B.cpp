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
		}
		a=(a*a);
		b>>=1;
	}
	return re;
}
struct no
{
	int pre=-1,cur=-1;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		string s[n];
		string d[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
		int c[n][10];
		FOR(i,0,n)
		{
			cin>>s[i];
			FOR(j,0,10)
			c[i][j]=-1;
			FOR(j,0,10)
			{
				int r=0;
				FOR(k,0,7)
				{
					if(s[i][k]=='1')
					{
						if(d[j][k]=='0')
						{
							r=10;
							break;
						}
					}
					else
					{
						if(d[j][k]=='1')
						r++;
					}
				}
				if(r==10)
				continue;
				c[i][j]=r;
			}
		}
		no dp[n+1][k+1];
		dp[0][0].cur=10;
		vector<int> a1,a2;
		a1.pb(0);
		FOR(i,0,n)
		{
			FOR(j,0,a1.size())
			{
				FORD(l,9,-1)
				{
					int v=c[i][l];
					if(c[i][l]!=-1)
					{
						if((a1[j]+v)>k)
						continue;
						if(dp[i+1][a1[j]+v].pre==-1)
						{
							dp[i+1][a1[j]+v].pre=a1[j];
							dp[1+i][a1[j]+v].cur=l;
							a2.pb(a1[j]+v);
						}
					}
				}
			}
			a1=a2;
			a2.clear();
		}
		if(dp[n][k].pre==-1)
		cout<<-1;
		else
		{
			int ans[n];
			int j=k;
			FORD(i,n,0)
			{
				ans[i-1]=dp[i][j].cur;
				j=dp[i][j].pre;
			}
			FOR(i,0,n)
			cout<<ans[i];
		}
	}
	return 0;
}