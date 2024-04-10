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
	cin>>test;
	while(test--)
	{
		ll s;
		cin>>s;
		ll r,a=0;
		while(s>=10)
		{
			r=s%10;
			a+=s;
			a-=r;
			s/=10;
			s+=r;
//			cout<<s<<' ';
		}
		a+=s;
		cout<<a<<'\n';
	}
	return 0;
}