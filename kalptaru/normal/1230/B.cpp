#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;
ll inf=1000000000000000002;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,k,cnt=0;
		cin>>n>>k;
		string s;
		cin>>s;
		if(k==0)
		{
			cout<<s;
			return 0;
		}
		if(n==1)
		{
			cout<<0;
			return 0;
		}
		if(s[0]!='1')
		{
			s[0]='1';
//			cout<<s<<' ';
			cnt=1;
//			cout<<'l';
		}
		FOR(i,1,n)
		{
			if(cnt==k)
			break;
			if(s[i]!='0')
			{
				s[i]='0';
				cnt++;
			}
		}
		cout<<s;
	}
	return 0;
}