#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 105
#define inf 1e9
#define ins insert
#define pb push_back
#define vi vector <int>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char s[maxn][maxn];
int n,m,x,y,r[maxn],c[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); m=read(); x=read(); y=read();
		rep(i,1,n) scanf("%s",s[i]+1);
		int F=0;
		rep(i,1,n) rep(j,1,m) if(s[i][j]=='B') F=1,r[i]=1,c[j]=1;
		if(s[x][y]=='B') puts("0");
		else if(r[x]||c[y]) puts("1");
		else if(F) puts("2");
		else puts("-1");
		
		rep(i,1,100) r[i]=0,c[i]=0;
	}
	return 0;
}