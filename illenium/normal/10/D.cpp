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

int a[505],b[505],f[505];
int p[505],w,max1;

void out(int t)
{
	if(t!=0)
	 out(p[t]),printf("%d ",b[t]);
}

int main()
{
	int n,m;
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	m=read();
	for(int i=1;i<=m;i++) b[i]=read();
	for(int i=1;i<=n;i++)
	{
		max1=0; w=0;
		for(int j=1;j<=m;j++)
		{
			if(a[i]>b[j]&&max1<f[j]) max1=f[j],w=j;
			if(a[i]==b[j]) f[j]=max1+1,p[j]=w;
		}
	}
	max1=-1;
	for(int i=1;i<=m;i++)
	 if(f[i]>max1) max1=f[i],w=i;
	printf("%d\n",max1);
	if(max1!=0) out(w);
	return 0;
}