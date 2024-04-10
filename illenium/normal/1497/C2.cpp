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

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),k=read();
		rep(i,1,k-3) printf("%d ",1),n--;
		if(n%2==1) printf("%d %d %d\n",1,(n-1)/2,(n-1)/2);
		else if(n%4==0) printf("%d %d %d\n",n/2,n/4,n/4);
		else printf("%d %d %d\n",2,n/2-1,n/2-1);
	}
	return 0;
}