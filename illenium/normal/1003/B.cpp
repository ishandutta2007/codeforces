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

int a,b,x,cnt;
char ch[maxn];

inline void dfs(int pre)
{
	if(x==1)
	{
		if(pre==0)
		{
			while(a) ch[++cnt]='0',a--;
			while(b) ch[++cnt]='1',b--;
		}
		else
		{
			while(b) ch[++cnt]='1',b--;
			while(a) ch[++cnt]='0',a--;
		}
		return;
	}
	else if(x==2)
	{
		if(pre==1) while(a) ch[++cnt]='0',a--;
		else while(b) ch[++cnt]='1',b--;
		while(a) ch[++cnt]='0',a--;
		while(b) ch[++cnt]='1',b--;
		return;
	}
	if(pre==1) ch[++cnt]='0',a--,x--,dfs(pre^1);
	else ch[++cnt]='1',b--,x--,dfs(pre^1);
	return;
}

int main()
{
	cin>>a>>b>>x;
	if(a>b) a--,ch[++cnt]='0',dfs(0);
	else b--,ch[++cnt]='1',dfs(1);
	for(int i=1;i<=cnt;i++) cout<<ch[i];
	return 0;
}