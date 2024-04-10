#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
#define pb push_back
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

int n;

int main()
{
	int T=read();
	while(T--)
	{
		n=read();
		if(n&1) printf("c"),n--;
		if(!n) {puts(""); continue;}
		int p=n/2;
		rep(i,1,p-1) printf("a"); printf("b");
		rep(i,1,p) printf("a");
		puts("");
		
	}
	return 0;
}