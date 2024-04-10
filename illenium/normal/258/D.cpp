#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
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

double dp[maxn][maxn],ans;
int a[maxn];

int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(a[i]>a[j]) dp[i][j]=1;
	}
	while(m--)
	{
		int p=read(),q=read();
		for(int i=1;i<=n;i++)
		{
			if(i==p||i==q) continue;
			dp[p][i]=dp[q][i]=(dp[q][i]+dp[p][i])/2;
			dp[i][p]=dp[i][q]=1-dp[q][i];
		}
		dp[p][q]=dp[q][p]=0.5;
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans+=dp[i][j];
	printf("%.9lf",ans);
	return 0;
}