#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
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
		int a[n];
		FOR(i,0,n)
		cin>>a[i];
		if(n<3)
		cout<<1;
		else
		{
			int an[n]={0},m=a[0],m2=0;
			bool ch[n]={0};
//			an[a[0]-1]--;
			FOR(i,1,n)
			{
				ch[m-1]=1;
				if(a[i]>m)
				{
					m2=m;
					m=a[i];
				}
				else if(a[i]>m2)
				{
					an[m-1]++;
					m2=a[i];
				}
			}
			ch[m-1]=1;
			
			m=-1,m2=0;
			FOR(i,0,n)
			{
//				cout<<ch[i]<<' ';
				if(an[i]>m)
				{
					m=an[i];
					m2=i;
				}
			}
			if(m==1)
			{
				FOR(i,0,m2)
				if(ch[i]==0)
				{
					m2=i;
					break;
				}
			}
			else if(m==0)
			{
				FOR(i,0,n)
				if(ch[i]==0)
				{
					m2=i;
					break;
				}
			}
			cout<<m2+1;
		}
	
	}
	return 0;
}