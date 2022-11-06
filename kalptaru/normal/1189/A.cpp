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
	int n,k=0;
	cin>>n;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		k++;
		else
		k--;		
	}
	if(k==0)
	{
		cout<<2<<"\n"<<s[0]<<' ';
		for(int i=1;i<s.size();i++)
		cout<<s[i];
	}
	else
	{
		cout<<1<<"\n"<<s;
	}
	return 0;
}