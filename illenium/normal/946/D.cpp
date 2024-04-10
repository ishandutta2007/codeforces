#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 1005
#define re register
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

char s[maxn][maxn];
int num[maxn],pos[maxn][maxn],dp[maxn],v[maxn][maxn],n,m,lim;

int main()
{
	n=read(); m=read(); lim=read();
	for(int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='1')
			{
				num[i]++;
				pos[i][num[i]]=j;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int k=0;k<=min(num[i]-1,lim);k++)
		{
			int res=inf;
			for(int p=0;p<=k;p++)
			{
				int q=(k-p);
				res=min(res,pos[i][num[i]-q]-pos[i][p+1]+1);
			}
			v[i][k]=m-res;
		}
		v[i][num[i]]=m;
	}
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		for(int j=lim;j>=0;j--)
		{
			for(int k=0;k<=min(j,m);k++)
				dp[j]=max(dp[j],dp[j-k]+v[i][k]);
		}
	}
	printf("%d\n",m*n-dp[lim]);
	return 0;
}