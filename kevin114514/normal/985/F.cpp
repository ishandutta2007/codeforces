#include<bits/stdc++.h>
using namespace std;
long long Hash[200100][26];
long long Mi[200100],Hasha[26],Hashb[26];
int N;
string S;
const long long mod=520131413;
void init()
{
	Mi[0]=1;
	for(int i=1;i<200100;i++)
		Mi[i]=Mi[i-1]*N%mod;
	for(int i=1;i<N;i++)
		for(int j=0;j<26;j++)
		{
			Hash[i][j]=Hash[i-1][j]*N%mod;
			if(S[i]=='a'+j)
				Hash[i][j]+=1;
		}
}
int main()
{
	int M;
	cin>>N>>M>>S;
	N++;
	S="-"+S;
	init();
	while(M--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		for(int i=0;i<26;i++)
			Hasha[i]=(Hash[a+c][i]+mod-(Hash[a][i]*Mi[c]%mod))%mod,
			Hashb[i]=(Hash[b+c][i]+mod-(Hash[b][i]*Mi[c]%mod))%mod;
		sort(Hasha,Hasha+26);
		sort(Hashb,Hashb+26);
		bool ok=true;
		for(int i=0;i<26;i++)
			if(Hasha[i]!=Hashb[i])
			{
				ok=false;
				break;
			}
		if(ok)
			puts("YES");
		else	puts("NO");
	}
	return 0;
}