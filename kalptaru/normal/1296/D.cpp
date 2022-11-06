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
ll m1=1000000007;
ll m2=67280421310721;
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
		ll a,b,k,o,h;
		cin>>n>>a>>b>>k;
		int ans=0;
		vector<ll> s;
		FOR(i,0,n)
		{
			cin>>h;
			if(((h-1)%(a+b)+1)<=a )
			ans++;
			else
			{
				o=((h-1)%(a+b)+1);
				if(o%a==0)
				{
					o=o/a-1;
				}
				else
				{
					o=o/a;
				}
				s.pb(o);
//				cout<<h<<' '<<o<<';';
			}
		}
		sort(s.begin(),s.end());
		FOR(i,0,s.size())
		{
//			cout<<s[i]<<' ';
			if(k>=s[i])
			{
				ans++;
				k-=s[i];
			}
			else
			break;
		}
		cout<<ans;
	}
	return 0;
}