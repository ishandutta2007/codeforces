#pragma GCC optimize(3,"Ofast","inline")
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

int n,a[maxn],l[maxn],r[maxn],f1,f2;

int main()
{
	n=read(); rep(i,1,n) a[i]=read();
	rep(i,2,n) if(a[i]>a[i-1]) l[i]=l[i-1]+1; else l[i]=0;
	rep(i,2,n) if(a[i]<a[i-1]) r[i]=r[i-1]+1; else r[i]=0;
	
	int tmp=0;
	rep(i,1,n) tmp=max(tmp,max(l[i],r[i]));
	rep(i,1,n) if(tmp==l[i]) f1++;
	rep(i,1,n) if(tmp==r[i]) f1++;
	
	
	if(f1>2) puts("0");
	else if(f1==2)
	{
		int F=0;
		rep(i,1,n) if(tmp==l[i]) {if(tmp==r[i+tmp]) F=1; break;}
		if(!F) puts("0");
		else if(tmp%2==0) puts("1"); else puts("0");
	}
	else puts("0");
	return 0;
}