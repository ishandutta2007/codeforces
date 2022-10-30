#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>s;
		int n=s.length(),has2=0;
		for(int i=n-2;i>=0;i--)
		{
			if(s[i]-'0'+s[i+1]-'0'>=10)
			{
				for(int j=0;j<i;j++)
					cout<<s[j];
				cout<<s[i]-'0'+s[i+1]-'0';
				for(int j=i+2;j<n;j++)
					cout<<s[j];
				has2=1;
				break;
			}
		}
		if(not has2)
		{
			cout<<s[0]-'0'+s[1]-'0';
			for(int j=2;j<n;j++)
				cout<<s[j];
		}
		cout<<"\n";
	}
	
	return 0;
}