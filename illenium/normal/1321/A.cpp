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

int a[maxn],b[maxn];

int main()
{
	int n=read(),f1=0,f2=0;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i]) continue;
		else if(a[i]==1&&b[i]==0) f1++;
		else if(a[i]==0&&b[i]==1) f2++;
	}
	if(f1==0) puts("-1");
	else cout<<f2/f1+1;
	return 0;
}