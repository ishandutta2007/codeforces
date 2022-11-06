#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=1000000007;
ll mod=67280421310721;
//ll mod=998244353;
//ll mod=163577857;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a)%mod;
		}
		a=(a*a)%mod;
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
		string s;
		cin>>s;
		int n=s.size();
		int pd[n][n];
		memset(pd,0,sizeof(pd));
		int ans[n]={0};
		FOR(k,1,2*n)
		{
			int i=k/2,j=k/2;
			if(k%2==0)
			i--;
			while(i>=0 && j<n)
			{
				if(s[i]==s[j])
				{
					pd[i][j]=1;
					ans[0]++;
				}
				else
				break;
				i--;
				j++;
			}
		}
		int mid;
		FOR(i,0,n)
		{
			FOR(j,0,(n-i))
			{
				mid=j+(i)/2;
				if(pd[j][i+j]!=0)
				{
					if(i==0)
					continue;
					else if((i%2)==0)
					{
						if(pd[j][mid-1]>0)
						{
							pd[j][j+i]=pd[j][mid-1]+1;
							ans[pd[j][mid-1]]++;
						}
					}
					else
					{
						if(pd[j][mid]>0)
						{
							pd[j][j+i]=pd[j][mid]+1;
							ans[pd[j][mid]]++;
						}
					}
				}
			}
		}
		FORD(i,n-1,1)
		ans[i]+=ans[i+1];
		FOR(i,0,n)
		cout<<ans[i]<<' ';
	}
	return 0;
}