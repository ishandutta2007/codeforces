#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[233];
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	int a[23];
	cin>>T;
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		cin>>s;
		for(auto ch:s)
			cnt[ch-'a']++;
		for(int i=0;i<26;i++)
			if(cnt[i]==2)
				cout<<(char)(i+'a');
		for(int i=0;i<26;i++)
			if(cnt[i]==1)
				cout<<(char)(i+'a');
		for(int i=0;i<26;i++)
			if(cnt[i]==2)
				cout<<(char)(i+'a');
		cout<<"\n";
	}
	
	return 0;
}