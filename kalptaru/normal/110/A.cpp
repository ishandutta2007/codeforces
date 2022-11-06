#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	int k=0;
	cin>>n;
	string s;
	stringstream ss;
	ss<<n;
	s=ss.str();	
	for(int i =0;i<s.size();i++)
	{
		if (s[i]=='4' || s[i]=='7')
		k+=1;
	}
	if(k==4 || k==7)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}