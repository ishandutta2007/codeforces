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

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,a[maxn],ans=inf;

inline ll jud(int x,int y)
{
	ll b1=a[1]+x,b2=a[2]+y,now=b2,tmp=0;
	for(int i=3;i<=n;i++)
	{
		now=now+(b2-b1);
		if(now==a[i]) continue;
		else if(abs(now-a[i])==1) tmp++;
		else return inf;
	}
	return tmp;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
			ans=min(ans,jud(i,j)+(i!=0)+(j!=0));
	if(ans>=inf) puts("-1");
	else cout<<ans<<endl;
	return 0;
}