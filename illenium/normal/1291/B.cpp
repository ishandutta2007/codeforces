#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 300005
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

int a[maxn],c[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		if(n%2==1)
		{
			int f=0;
			for(int i=1;i<=n;i++)
			{
				int tmp=min(i-1,n-i);
				if(a[i]<tmp) {f=1; break;}
			}
			if(f==0) puts("Yes");
			else puts("No");
		}
		else
		{
			int f=0;
			for(int i=1;i<=n;i++)
			{
				int tmp=min(i-1,n-i); c[i]=tmp;
				if(a[i]<tmp) {f=1; break;}
			}
			if(f==0)
			{
				if(a[n/2]==c[n/2]&&a[n/2+1]==c[n/2+1]) puts("No");
				else puts("Yes");
			}
			else puts("No");
		}
	}
	return 0;
}