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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		string s;
		int a;
		int stk[n];
		int k=-1,j=1,l=-1,ans=0;
		FOR(i,0,2*n)
		{
			cin>>s;
			if(s[0]=='r')
			{
				if(k<l)
				{
					j++;
				}
				else if(stk[k]==j)
				{
					k--;
					j++;
				}
				else
				{
					l=k+1;
					ans++;
					j++;
				}
			}
			else
			{
				cin>>a;
				k++;
				stk[k]=a;
			}
		}
		cout<<ans;
	}
	return 0;
}