#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxn 1000005
#define inf 1e9
#define ins insert
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ull c[2505][2505];
const ull base=998244353;
int n,m,q;

inline void add(int x,int y,int w)
{
	for(int i=x;i<=n;i+=i&-i) for(int j=y;j<=m;j+=j&-j) c[i][j]+=w;
}

inline ull gt(int x,int y)
{
	ull ret=0;
	for(int i=x;i;i-=i&-i) for(int j=y;j;j-=j&-j) ret+=c[i][j];
	return ret;
}

inline ull gh(int a,int b,int c,int d)
{
	ull ret=a; ret*=base; ret+=b;
	ret*=base; ret+=c;
	ret*=base; ret+=d; return ret;
}

int main()
{
	n=read(); m=read(); q=read();
	while(q--)
	{
		int opt=read(),x=read(),y=read(),X=read(),Y=read();
		if(opt==3)
		{
			if(gt(x,y)==gt(X,Y)) puts("Yes");
			else puts("No");
		}
		else
		{
			int tmp=opt==1?1:-1; ull tmp2=gh(x,y,X,Y); tmp2*=tmp;
			add(x,y,tmp2); add(x,Y+1,-tmp2);
			add(X+1,y,-tmp2); add(X+1,Y+1,tmp2);
		}
	}
	return 0;
}