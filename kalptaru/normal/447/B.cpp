#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	ll ans=0;
	ll k,i=0,m=-1,n=s.size();
	cin>>k;
	ll f[26];
	while(i<26)
	{
		cin>>f[i];
		if(f[i]>m)
		m=f[i];
		i++;
	}
	for(i=0;i<n;i++)
	ans+=((i+1)*(f[s[i]-'a']));
	ans+=((((n+k)*(n+k+1))-(n*(n+1)))*m)>>1;
	cout<<ans;
	return 0;
}