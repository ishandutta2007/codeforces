#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a=0;
	cin>>n;
	string s;
	char p;
	cin>>s;
	p=s[0];
	for(int i=1;i<n;i++)
	{
		if(s[i]==p)
		a+=1;
		else
		p=s[i];	
	}
	cout<<a;
	return 0;
}