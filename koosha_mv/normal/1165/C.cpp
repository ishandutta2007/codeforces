#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	string p;
	for(int i=0;i<n;i++)
	{
		if(p.size()%2==0 || p.back()!=s[i])
			p.push_back(s[i]);
	}
	if(p.size()%2==1)p.pop_back();
	cout<<n-p.size()<<endl<<p<<endl;
}