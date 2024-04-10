#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
#define inf 1e18
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,p,k,sta[maxn];
struct node{int a,val[10];}x[maxn];
ll dp[maxn][128];

inline bool cmp(node a,node b){return a.a>b.a;}

int main()
{
	n=read(); p=read(); k=read();
	for(int i=1;i<=n;i++) x[i].a=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=p;j++) x[i].val[j]=read();
	sort(x+1,x+n+1,cmp);
	int ed=(1<<p)-1;
	for(int i=1;i<=ed;i++) sta[i]=sta[i>>1]+(i&1);
	for(int i=0;i<=n;i++) for(int s=0;s<=ed;s++) dp[i][s]=-inf; dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int s=0;s<=ed;s++)
		{
			int nw=i-sta[s];
			if(nw<=k) dp[i][s]=max(dp[i][s],dp[i-1][s]+x[i].a);
			else dp[i][s]=dp[i-1][s];
			for(int j=1;j<=p;j++)
			{
				if((s&(1<<(j-1)))!=0)
					dp[i][s]=max(dp[i][s],dp[i-1][s^(1<<(j-1))]+x[i].val[j]);
			}
		}
	}
	cout<<dp[n][ed]<<endl;
	return 0;
}