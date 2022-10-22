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

char ch[2005][2005];
int cnt[2005],n,m;

int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;i++) cin>>(ch[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(ch[i][j]=='1') cnt[j]++;
	}
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		flag=0;
		for(int j=1;j<=m;j++)
		{
			if(ch[i][j]=='1') {flag=1; break;}
		}
		if(flag==0) {puts("YES"); return 0;}
	}
	flag=0;
	for(int i=1;i<=n;i++)
	{
		flag=0;
		for(int j=1;j<=m;j++)
		{
			if(cnt[j]==1&&ch[i][j]=='1') {flag=1; break;}
		}
		if(flag==0) {puts("YES"); return 0;}
	}
	puts("NO");
	return 0;
}