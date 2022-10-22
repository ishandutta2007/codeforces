#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--)
	{
		string s;
		cin>>s;
		if(s.size()==2)
			cout<<s[1]<<"\n";
		else
		{
			char c='9';
			for(auto v:s)
				c=min(c,v);
			cout<<c<<"\n";
		}
	}
	return 0;
}