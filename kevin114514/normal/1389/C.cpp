#include<bits/stdc++.h>
using namespace std;
int Count(string S,char a,char b)
{
	int ret=0;
	for(int i=0;i<S.length();i++)
		if(S[i]==a&&ret%2==0)
			ret++;
		else if(S[i]==b&&ret%2)
			ret++;
	return ret;
}
int CCount(string S,char c)
{
	int ret=0;
	for(int i=0;i<S.length();i++)
		if(S[i]==c)
			ret++;
	return ret;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		int Ans=0;
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				Ans=max(Ans,Count(S,i+'0',j+'0')/2*2);
		for(int i=0;i<10;i++)
			Ans=max(Ans,CCount(S,i+'0'));
		cout<<S.length()-Ans<<endl;
	}
	return 0;
}