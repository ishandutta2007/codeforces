#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a,b,c;
	cin>>a>>b;
	for (int i=0;i<a.size();i++)
	{
		if(a[i]==b[i])
		c.append("0");
		else
		c.append("1");		
	}
	cout<<c;
	return 0;
}