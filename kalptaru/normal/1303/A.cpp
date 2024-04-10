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
		string s;
		cin>>s;
		int t=-1,e;
		FOR(i,0,s.size())
		{
			if(t==-1 && s[i]=='1')
			t=i;
			if(s[i]=='1')
			e=i;
		}
		int c=0;
		FOR(i,t,e+1)
		{
			if(s[i]=='0')
			c++;
		}
		if(t==-1)
		c=0;
		cout<<c<<'\n';
	}
	return 0;
}