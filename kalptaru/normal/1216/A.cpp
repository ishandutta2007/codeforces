#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,ans=0;
		cin>>n;
		string s;
		cin>>s;
		for(int i=0;i<n;i+=2)
		{
			if(s[i]==s[i+1])
			{
				ans++;
				s[i]='a';
				s[i+1]='b';
			}
		}
		cout<<ans<<'\n'<<s;
	}
	return 0;
}