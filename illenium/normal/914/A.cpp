#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

void write(int x)
{
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

int n,a[1005],ans=-1e9;

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(sqrt(a[i])==floor(sqrt(a[i]))) continue;
		else ans=max(ans,a[i]);
	}
	cout<<ans;
	return 0;
}