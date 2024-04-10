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

ll n,a,b,s,t,ans;
struct node{ll hp,dmg,d;};
node c[200005];

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

inline bool cmp(node a,node b){return a.d>b.d;}

int main()
{
	n=read(); a=read(); b=read();
	b=min(b,n);
	for(int i=1;i<=n;++i)
	{
		c[i].hp=read(); c[i].dmg=read();
		c[i].d=max(0ll,c[i].hp-c[i].dmg);
		s+=c[i].dmg;
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=b;i++) t+=c[i].d;
	for(int i=1;i<=b;i++) ans=max(ans,t-c[i].d+(c[i].hp<<a)-c[i].dmg);
	for(int i=b+1;i<=n;i++) ans=max(ans,t-c[b].d+(c[i].hp<<a)-c[i].dmg);
	if(!b) ans=0;
	cout<<s+ans<<endl;
	return 0;
}