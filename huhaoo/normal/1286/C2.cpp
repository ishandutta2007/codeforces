/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-01-05 22:40:28
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const int N=110;
char s[N*N][N];
int n;
#include<vector>
std::vector<int> e[N];
std::vector<std::pair<int,std::pair<char,char> > > v[N];
struct info
{
	int cnt[26];
	info(){ memset(cnt,0,sizeof(cnt)); }
	int &operator[](int a){ return cnt[a]; }
	void insert(char *c,int l){ fr(i,0,l-1) cnt[c[i]-'a']++; }
}a[N];
info operator+(info a,info b)
{
	info c;
	fr(i,0,25) c[i]=a[i]+b[i];
	return c;
}
info operator-(info a,info b)
{
	info c;
	fr(i,0,25) c[i]=a[i]-b[i];
	return c;
}
char ans[N];
#define mp std::make_pair
void solve(int n,int d=0)
{
	printf("? %d %d\n",1+d,n+d); fflush(stdout);
	fr(i,0,::n){ e[i].clear(); fr(j,0,25) a[i][j]=0; }
	fr(i,1,n*(n+1)/2)
	{
		scanf("%s",s[i]);
		e[strlen(s[i])].push_back(i);
	}
	int m=0;
	fd(i,n,1)
	{
		if(i<n-i+1) break;
		m=i;
		for(auto j:e[i])
		{
			a[i].insert(s[j],i);
		}
	}
//	fr(i,1,n) fr(j,0,25) printf("%d%c",a[i][j],j==25?'\n':' ');
	fr(i,m,n) a[i]=a[i]-a[i+1];
	fd(i,n,m) a[i]=a[i]-a[i-1];
	fr(i,m,n)
	{
//		fr(j,0,25) printf("%d%c",a[i][j],j==25?'\n':' ');
		if(i==n-i+1)
		{
			fr(j,0,25) if(a[i][j]) ans[i+d]=j+'a';
//			printf("%d %c\n",i,ans[i]);
			continue;
		}
		char c1=0,c2=0;
		fr(j,0,25) if(a[i][j])
		{
			if(c1) c2=j+'a';
			else c1=j+'a';
		}
		if(!c2) c2=c1;
//		printf("%d %d %c %c\n",i,n-i+1,c1,c2);
		v[i+d].push_back(mp(n-i+1+d,mp(c1,c2)));
		v[n-i+1+d].push_back(mp(i+d,mp(c1,c2)));
	}
}
void dfs(int u)
{
	for(auto e:v[u]) if(!ans[e.first])
	{
		ans[e.first]=e.second.first^e.second.second^ans[u];
		dfs(e.first);
	}
}
int main()
{
	n=read();
	solve(n);
	int l=n/2;
	if(l>0) solve(l);
	if(l-1>0) solve(l-1,n-l);
	fr(i,1,n) if(ans[i]) dfs(i);
	printf("! %s\n",ans+1);
	return 0;
}
/*
4
a a b c aa ab bc aab abc aabc
a a b aa ab aab
*/