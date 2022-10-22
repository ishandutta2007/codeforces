#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 530005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

string s1;
ll m,dp[maxn][105],len,ed,cnt[maxn],fac[maxn],tmp;

int main()
{
	cin>>s1; cin>>m;
	len=s1.length(); ed=(1<<len)-1; fac[0]=1;
	for(int i=1;i<=len;i++) fac[i]=fac[i-1]*i;
	for(int i=0;i<len;i++) cnt[s1[i]-'0']++; tmp=1;
	for(int i=0;i<=9;i++) tmp*=fac[cnt[i]];
	for(int i=0;i<len;i++)
	{
		if(s1[i]-'0'==0) continue;
		else dp[1<<i][(s1[i]-'0')%m]=1;
	}
	for(int s=1;s<=ed;s++)
	{
		for(int i=1;i<=len;i++)
		{
			if(s&(1<<(i-1))) continue;
			for(int j=0;j<m;j++) dp[s|(1<<(i-1))][(j*10+(s1[i-1]-'0'))%m]+=dp[s][j];
		}
	}
	cout<<dp[ed][0]/tmp<<endl;
	return 0;
}