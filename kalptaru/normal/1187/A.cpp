 #include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,s,g;
		cin>>n>>s>>g;
		if(g<s)
		s=g;
		cout<<n-s+1<<"\n";
	}
	return 0;
}