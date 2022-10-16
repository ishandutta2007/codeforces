#include<bits/stdc++.h>
using namespace std;
int P[500500];
long long ans,cnt;
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>P[i];
	string S;
	cin>>S;
	for(int i=0;i<S.length();i++)
		if(S[i]=='B')
			cnt+=P[i];
	for(int i=0;i<S.length();i++)
	{
		if(S[i]=='B')
			cnt-=P[i];
		else	cnt+=P[i];
		ans=max(ans,cnt);
	}
	for(int i=0;i<S.length();i++)
	{
		if(S[i]=='B')
			cnt+=P[i];
		else	cnt-=P[i];
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}