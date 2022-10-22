#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
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

struct node{int x,y,w;}p[maxn];
int n,m,ct;

inline bool cmp(node a,node b){return a.w<b.w;}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); m=read(); ct=0;
		rep(i,1,n) rep(j,1,m) p[++ct].x=i,p[ct].y=j,p[ct].w=max(i-1,n-i)+max(j-1,m-j);
		sort(p+1,p+ct+1,cmp);
		rep(i,1,ct) printf("%d ",p[i].w);
		puts("");
	}
	return 0;
}