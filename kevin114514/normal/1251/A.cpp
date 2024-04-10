#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string S;
		set<char> s;
		cin>>S;
		S+='0';
		int l=0,r=0;
		while(r<S.length())
		{
			if(S[r]==S[l])
				r++;
			else
			{
				if((r-l)%2==1)
					s.insert(S[l]);
				l=r;
			}
		}
		for(set<char>::iterator it=s.begin();it!=s.end();it++)
			cout<<*it;
		puts("");
	}
	return 0;
}