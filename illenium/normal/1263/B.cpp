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

map <int,int> mp,mp2;
int xx[maxn];
bool vis[maxn];

inline void pr(int x)
{
	if(x/1000) printf("%d\n",x);
	else if(x/100) cout<<"0",printf("%d\n",x);
	else if(x/10) cout<<"00",printf("%d\n",x);
	else if(x) cout<<"000",printf("%d\n",x);
	else puts("0000");
}

inline void sol(int q)
{
	int x,tmp;
	x=xx[q]/1000*1000+xx[q]%100;
	for(int i=0;i<=9;i++)
	{
		tmp=i*100+x;
		if(mp2[tmp]==0) {mp2[tmp]=1; pr(tmp); return;}
	}
	x=xx[q]/100*100+xx[q]%10;
	for(int i=0;i<=9;i++)
	{
		tmp=i*10+x;
		if(mp2[tmp]==0) {mp2[tmp]=1; pr(tmp); return;}
	}
	x=xx[q]/10*10;
	for(int i=0;i<=9;i++)
	{
		tmp=i+x;
		if(mp2[tmp]==0) {mp2[tmp]=1; pr(tmp); return;}
	}
	x=xx[q]%1000,tmp;
	for(int i=0;i<=9;i++)
	{
		tmp=i*1000+x;
		if(mp2[tmp]==0) {mp2[tmp]=1; pr(tmp); return;}
	}
}

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),ans=0;
		for(int i=1;i<=n;i++)
		{
			int x=read(); xx[i]=x;
			if(mp[x]) ans++; mp[x]++;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			if(mp2[xx[i]]) vis[i]=1;
			else mp2[xx[i]]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) sol(i);
			else pr(xx[i]);
		}
		for(int i=1;i<=n;i++) vis[i]=0;
		mp.clear(); mp2.clear();
	}
	return 0;
}