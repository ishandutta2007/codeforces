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

int a[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),f=0,f1=0,f2=0;
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++)
		{
			if(a[i]%2==0) {f=i; break;}
			else if(f1==0) f1=i;
			else if(f2==0) f2=i;
		}
		if(f) printf("1\n%d\n",f);
		else if(f1!=0&&f2!=0) printf("2\n%d %d\n",f1,f2);
		else puts("-1");
	}
	return 0;
}