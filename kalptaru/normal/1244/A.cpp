#include <bits/stdc++.h>
#include <string>
#include <cmath>
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
	ll t=1;
	cin>>t;
	while ( t-- ) 
	{
		int a,b,x,y,k,v,s;
		cin>>a>>b>>x>>y>>k;
		v=(a+x-1)/x;
		s=(b+y-1)/y;
		if(v+s>k)
		cout<<-1<<'\n';
		else
		cout<<v<<' '<<s<<'\n';
	}
	return 0;
}