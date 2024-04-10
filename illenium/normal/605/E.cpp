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
#define eps 1e-12
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n;
double p[maxn][maxn],m[maxn],A[maxn],B[maxn];
bool vis[maxn];

inline int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	return 1;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lf",&p[i][j]),p[i][j]/=100;
	for(int i=1;i<=n;i++) A[i]=B[i]=1,m[i]=1e30;
	m[n]=0;
	for(int i=1;i<=n;i++)
	{
		int u=-1;
		double tmp=1e10;
		for(int j=1;j<=n;j++) if(m[j]<tmp&&!vis[j]) tmp=m[j],u=j;
		vis[u]=1;
		for(int x=1;x<=n;x++)
		{
			if(vis[x]) continue;
			B[x]+=A[x]*p[x][u]*m[u];
			A[x]*=1-p[x][u];
		}
		for(int x=1;x<=n;x++)
		{
			if(vis[x]) continue;
			if(dcmp(1-A[x])==0) m[x]=1e30;
			else m[x]=B[x]/(1-A[x]);
		}
	}
	printf("%.12lf",m[1]);
	return 0;
}