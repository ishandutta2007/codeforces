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
#define eps 1e-10
#define tl (k<<1)
#define tr (k<<1|1)
#define mid (l+r>>1)
#define P pair<int,int>
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

const int MAX=5e5+1;
int ans[MAX],l[MAX],v[MAX],pr[MAX],n,m;
P s[MAX<<2];
vector<int> a[MAX];

inline P Min(P a,P b)
{
	if(!a.first) return b;
	if(!b.first) return a;
	return min(a,b);
}

inline void pus(int k){s[k]=Min(s[tl],s[tr]);}

inline void change(int l,int r,int k,int x,int a,int b)
{
	if(l==r)
	{
		s[k].first=a,s[k].second=b;
		return;
	}
	if(x<=mid) change(l,mid,tl,x,a,b);
	else change(mid+1,r,tr,x,a,b);
	pus(k);
}

inline P ask(int l,int r,int k,int L,int R)
{
	if(l==L&&r==R) return s[k];
	if(R<=mid) return ask(l,mid,tl,L,R);
	if(L>mid) return ask(mid+1,r,tr,L,R);
	return Min(ask(l,mid,tl,L,mid),ask(mid+1,r,tr,mid+1,R));
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) v[i]=read(); m=read();
	for(int i=1,r;i<=m;i++)
	{
		l[i]=read(),r=read();
		a[r].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(pr[v[i]]) change(1,n,1,pr[v[i]],0,0);
		change(1,n,1,i,pr[v[i]]+1,v[i]);
		pr[v[i]]=i;
		for(int j=0;j<a[i].size();j++)
		{
			P Ans=ask(1,n,1,l[a[i][j]],i);
			if(Ans.first<=l[a[i][j]]) ans[a[i][j]]=Ans.second;
		}
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}