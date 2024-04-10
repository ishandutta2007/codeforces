#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		map<ll ,int > mp;
		while(a < b && !mp[a]){
			mp[a] = 1;
			if(a%2 == 0)
				a = a*3/2;
			else
				a--;
		}
		if(a >= b){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
		
		
	}
	return 0;
 }