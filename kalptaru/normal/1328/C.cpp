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
ll mod3=998244353;
ll INF=1e18;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int a[n],b[n];
		if(s[0]=='1')
		{
			a[0]=b[0]=2;
		}
		else
		{
			a[0]=b[0]=1;
		}
		int in=1;
		FOR(i,1,n)
		{
			in++;
			if(s[i]=='0')
			{
				a[i]=b[i]=0;
			}
			else if(s[i]=='1')
			{
				a[i]=1;
				b[i]=0;
				break;
			}
			else
			{
				a[i]=b[i]=1;
			}
		}
		FOR(i,in,n)
		{
			a[i]=0;
			b[i]=s[i]-'0';
		}
		FOR(i,0,n)
		cout<<a[i];
		cout<<'\n';
		FOR(i,0,n)
		cout<<b[i];
		cout<<'\n';
	}
	return 0;
}