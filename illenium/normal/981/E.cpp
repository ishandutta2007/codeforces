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
#include<bitset>
#define ll long long
#define maxn 10005
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

bitset <maxn> s[maxn<<2];
vector <int> a[maxn<<2];
int n,m;

inline void change(int x,int l,int r,int l1,int r1,int v)
{
	if(l1==l&&r1==r)
	{
		a[x].push_back(v);
		return;
	}
	int mid=(l+r)>>1;
	if(r1<=mid) change(x<<1,l,mid,l1,r1,v);
	else if(l1>mid) change(x<<1|1,mid+1,r,l1,r1,v);
	else
	{
		change(x<<1,l,mid,l1,mid,v);
		change(x<<1|1,mid+1,r,mid+1,r1,v);
	}
}

inline void query(int x,int l,int r)
{
	if(l==r)
	{
		s[x][0]=1;
		for(int i=0;i<a[x].size();i++) s[x]=s[x]<<a[x][i]|s[x];
		return;
	}
	int mid=(l+r)>>1;
	query(x<<1,l,mid); query(x<<1|1,mid+1,r);
	s[x]=s[x<<1]|s[x<<1|1];
	for(int i=0;i<a[x].size();i++) s[x]=s[x]<<a[x][i]|s[x];
}

int main()
{
	n=read(); m=read();
	for(int i=1;i<=m;i++)
	{
		int l=read(),r=read(),x=read();
		change(1,1,n,l,r,x);
	}
	query(1,1,n); int tot=0;
	for(int i=1;i<=n;i++) if(s[1][i]) ++tot; cout<<tot<<endl;
	for(int i=1;i<=n;i++) if(s[1][i]) printf("%d ",i);
	return 0;
}