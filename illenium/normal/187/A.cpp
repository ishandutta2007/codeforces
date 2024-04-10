#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
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

int a[maxn],b[maxn],p[maxn],p2[maxn],n,cnt,p3[maxn],F;

int main()
{
	n=read(); rep(i,1,n) a[i]=read(),p[a[i]]=i; F=n+1;
	rep(i,1,n) b[i]=read(),p2[i]=p[b[i]];
	
	rep(i,1,n) p3[p2[i]]=i;
	rep(i,1,n) if(p3[i]<p3[i-1]) {F=i; break;}
	cout<<n-F+1<<endl;
	return 0;
}