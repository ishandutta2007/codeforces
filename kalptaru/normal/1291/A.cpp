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
		int sum=0;
		cin>>n;
		string s;
		cin>>s;
		int e=0;
		int r=-1;
		FOR(i,0,n)
		{
			sum+=(s[i]-'0');
		}
		if(sum%2==0)
		{
			FOR(i,0,n)
			{
				if((s[n-i-1]-'0')%2==1)
				{
					e=n-i-1;
					break;
				}
			}
		}
		else
		{
			bool f=1;
			FOR(i,0,n)
			{
				if((s[n-i-1]-'0')%2==1)
				{
					if(f)
					{
						f=0;
					}
					else
					{
						e=n-i-1;
						break;
					}
				}
			}
		}
		if(e==0)
		{
			cout<<-1<<'\n';
		}
		else
		{
			FOR(i,0,e+1)
			cout<<s[i];
			cout<<'\n';
		}
	}
	return 0;
}