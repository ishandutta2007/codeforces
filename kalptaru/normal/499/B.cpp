#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	map <string ,string> c;
	string a,b;
	for (int i=0;i<m;i++)
	{
		cin>>a>>b;
		if(a.size()>b.size())
		c.insert(pair<string,string>(a,b));
		else
		c.insert(pair<string,string>(a,"?"));
	}
	for (int i=0;i<n;i++)
	{
		cin>>a;
		if(c[a]=="?")
		cout<<a<<' ';
		else
		cout<<c[a]<<' ';
	}
	return 0;
}