#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
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
		int n=read(),f1=0,f2=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			int x=read(); sum+=x;
			if(x%2==0) f1=1;
			else f2=1;
		}
		if(f1+f2==2) puts("YES");
		else if(sum%2==1) puts("YES");
		else puts("NO");
	}
	return 0;
}