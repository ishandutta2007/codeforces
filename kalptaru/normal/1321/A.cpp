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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int a[n],b[n];
		FOR(i,0,n)
		{	
			cin>>a[i];
		}
		FOR(i,0,n)
		{
			cin>>b[i];
		}
		int r=0,s=0;
		FOR(i,0,n)
		{
			if(a[i]==1)
			{
				if(b[i]==0)
				{
					r++;
				}
				
			}
			else
			{
				if(b[i]==1)
				{
					s++;
				}
			}
		}
		if(r==0)
		{
			cout<<-1;
			return 0;
		}
		s++;
		int ans;
		if(s%r==0)
		{
			ans=s/r;
		}
		else
		ans=s/r+1;
		cout<<max(1,ans);
	}
	return 0;
}