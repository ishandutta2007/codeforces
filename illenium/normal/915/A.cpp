#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int ans=1e9,a[105],n,k;

int main()
{
	n=read(); k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(k%a[i]==0) ans=min(ans,k/a[i]);
	}
	cout<<ans;
	return 0;
}