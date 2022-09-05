#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=100+5;
string s[N][2];int id[N][2];
bool dp[N][2];
char ans[N*2];

bool is_p(string s,string t)
{
	rep(i,0,int(s.size())-1)
	if(s[i]!=t[i])return 0;
	return 1;
}
bool is_s(string s,string t)
{
	int d=t.size()-s.size();
	rep(i,0,int(s.size())-1)
	if(s[i]!=t[d+i])return 0;
	return 1;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n;
	cin>>n;
	rep(i,1,2*n-2)
	{
		string t;
		cin>>t;
		int len=t.size();
		int j=s[len][0].empty()^1;
		s[len][j]=t;
		id[len][j]=i;
	}
	rep(i,0,1)dp[1][i]=1;
	rep(i,2,n-1)
	rep(j,0,1)
	rep(k,0,1)
	if(dp[i-1][k]&&is_p(s[i-1][k],s[i][j])&&is_s(s[i-1][k^1],s[i][j^1]))
		dp[i][j]=1;
	int j=0;
	if(!dp[n-1][j])j=1;
	string ans_s=s[n-1][j]+s[n-1][j^1].back();
	rep(i,1,n-1)
	{
		int j=0;
		if(is_p(s[i][0],ans_s))j=0;
		else j=1;
		ans[id[i][j]]='P';
		ans[id[i][j^1]]='S';
	}
	printf("%s\n",ans+1);
}