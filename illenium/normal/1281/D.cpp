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

int sum[1005][1005],a[1005][1005];

inline int gets1(int a,int b,int c,int d)
{
	return sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1];
}


int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) sum[i][j]=0;
		char s[1005][1005];
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='A') a[i][j]=1;
				else a[i][j]=0;
				//cout<<a[i][j];
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) sum[i][j]=sum[i-1][j]+sum[i][j-1]+a[i][j]-sum[i-1][j-1];
		if(sum[n][m]==n*m)
		{
			puts("0");
			continue;
		}
		else if(sum[n][m]==0)
		{
			puts("MORTAL");
			continue;
		}
		else
		{
			int fl=0,f2=0;
			if(gets1(1,1,1,m)==m||gets1(1,1,n,1)==n||gets1(1,m,n,m)==n||gets1(n,1,n,m)==m) {puts("1"); continue;}
			if(a[1][1]==1||a[1][m]==1||a[n][1]==1||a[n][m]==1) {puts("2"); continue;}
			for(int i=1;i<=n;i++) if(gets1(i,1,i,m)==m) {fl=1; break;}
			for(int i=1;i<=m;i++) if(gets1(1,i,n,i)==n) {fl=1; break;}
			if(fl==1) {puts("2"); continue;}
			for(int i=1;i<=n;i++) if(a[i][m]==1||a[i][1]==1) {f2=1; break;}
			for(int i=1;i<=m;i++) if(a[n][i]==1||a[1][i]==1) {f2=1; break;}
			if(f2==1) {puts("3"); continue;}
			puts("4");
		}
	}
	return 0;
}