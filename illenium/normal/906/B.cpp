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
#define maxn 100005
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

int p[maxn],n,m;
const int vx[4]={0,0,1,-1};
const int vy[4]={1,-1,0,0};

inline bool jud(int i,int j)
{
	int x1=i/m,y1=i%m,x2=j/m,y2=j%m;
	for(int d=0;d<=3;d++) if(x2==x1+vx[d]&&y2==y1+vy[d]) return 1;
	return false;
}

inline bool dfs(int i)
{
	if(i==n*m) return 1;
	int x=i/m,y=i%m;
	for(int j=i;j<n*m;j++)
	{
		swap(p[i],p[j]);
		bool ok=1;
		if(x&&jud(p[i],p[(x-1)*m+y])) ok=0;
		if(y&&jud(p[i],p[x*m+y-1])) ok=0;
		if(ok) if(dfs(i+1)) return 1;
		swap(p[j],p[i]);
	}
	return 0;
}

int main()
{
	n=read(); m=read();
	for(int i=1;i<=n*m;i++) p[i]=i;
	if(dfs(0))
	{
		puts("YES");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%d ",p[i*m+j]+1);
			puts("");
		}
	}
	else puts("NO");
	return 0;
}