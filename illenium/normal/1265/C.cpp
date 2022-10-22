#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 500005
#define re register
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

int a[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(); int tmp=n/2;
		for(int i=1;i<=n;i++) a[i]=read();
		int f=n+1,g=0,s=0,b=0;
		int tmpg,tmps,tmpb;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[1])
			{
				f=i-1;
				break;
			}
		}
		if(f==n+1) {puts("0 0 0"); continue;}
		tmpg=a[1]; g=f;
		int f2=n+1;
		for(int i=2*f+2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				f2=i-1;
				break;
			}
		}
		if(f2==n+1) {puts("0 0 0"); continue;}
		s=f2-f;
		int f3=n+1;
		for(int i=f2+g+2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				f3=i-1;
				break;
			}
		}
		int ed=0;
		for(int i=tmp;i>=0;i--)
		{
			if(a[i]!=a[tmp+1])
			{
				ed=i;
				break;
			}
		}
		if(f3==n+1||f3>ed) {puts("0 0 0"); continue;}
		printf("%d %d %d\n",g,s,ed-f2);
	}
	return 0;
}