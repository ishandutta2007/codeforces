#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		if(n==2 && ((s[0]-'0')>=(s[1]-'0')))
		cout<<"NO\n";
		else
		{
		
		
			cout<<"YES\n2\n";
			cout<<s[0]<<' ';
			FOR(i,1,n)
			cout<<s[i];
			cout<<'\n';
		}
		
	}
	return 0;
}