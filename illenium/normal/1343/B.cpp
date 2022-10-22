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

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(); n/=2;
		if(n%2==1) puts("NO");
		else
		{
			puts("YES");
			rep(i,1,n) printf("%d ",2*i);
			rep(i,1,n-1) printf("%d ",2*i-1); printf("%d\n",2*n-1+n);
		}
	}
	return 0;
}