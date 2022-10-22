#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,i;
	string s;
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>s;
		sort(s.begin(),s.end());
		if(s[0]==s[s.size()-1])
			cout<<"-1\n";
		else
			cout<<s<<"\n";
	}
	return 0;
}