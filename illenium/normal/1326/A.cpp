#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
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
		int n=read();
		if(n==1) puts("-1");
		else if(n==2) puts("57");
		else
		{
			for(int i=1;i<=n-2;i++) printf("2");
			int tmp=(2*(n-1))%9;
			if(tmp==0) printf("49");
			else printf("29"); puts("");
		}
	}
	return 0;
}