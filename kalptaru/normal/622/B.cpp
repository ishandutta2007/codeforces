#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) ;for (int i = (a); i < (b); i++)
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
//	cin>>t;
	while ( t-- ) 
	{
		string s;
		cin>>s;
		int h=((s[0]-'0')*10+(s[1]-'0'));
		int m=((s[3]-'0')*10+(s[4]-'0'));
		int a;
		cin>>a;
		m+=a;
		h+=(m/60);
		if(h%24<10)
		cout<<'0';
		cout<<h%24<<':';
		if(m%60<10)
		cout<<'0';
		cout<<m%60;
	}
	return 0;
}