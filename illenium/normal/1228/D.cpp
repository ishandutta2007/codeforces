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

int n,m;
vector <int> mp[maxn];
map <vector<int>,int> p;
map <int,vector<int> > a;
int fa,fb,fc;

int main()
{
	n=read(); m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	for(int i=1;i<=n;i++) sort(mp[i].begin(),mp[i].end());
	for(int i=1;i<=n;i++)
	{
		if(p[mp[i]]==0)
		{
			p[mp[i]]=1;
			if(!fa) a[1]=mp[i],fa=1;
			else if(!fb) a[2]=mp[i],fb=1;
			else if(!fc) a[3]=mp[i],fc=1;
			else {puts("-1"); return 0;}
		}
	}
	if(!fc) {puts("-1"); return 0;}
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++)
	{
		if(mp[i]==a[1]) cnt1++;
		else if(mp[i]==a[2]) cnt2++;
		else cnt3++;
	}
	if(cnt1*cnt2+cnt2*cnt3+cnt1*cnt3!=m) puts("-1");
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(mp[i]==a[1]) printf("1 ");
			else if(mp[i]==a[2]) printf("2 ");
			else printf("3 ");
		}
	}
	return 0;
}