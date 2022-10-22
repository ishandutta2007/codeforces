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
#define maxn 200005
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

int k,n,ans,x=1,y=1,now,num[105][105];
char m[105][105];

int main()
{
	//freopen("CF965B.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%s",m[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1,u;j<=n;j++)
		{
			for(u=i;u<=i+k-1&&u<=n;u++) if(m[u][j]=='#') break;
			if(u>i+k-1) for(int u=i;u<=i+k-1;u++) num[u][j]++;
			for(u=j;u<=j+k-1&&u<=n;u++) if(m[i][u]=='#') break;
			if(u>j+k-1) for(u=j;u<=j+k-1;u++) num[i][u]++;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(num[i][j]>ans) ans=num[i][j],x=i,y=j;
	printf("%d %d",x,y);
	return 0;
}