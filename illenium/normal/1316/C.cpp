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

int a[maxn],b[maxn],p,n,m,c[maxn],d[maxn],c1,c2,f1,f2;

int main()
{
	srand(time(0));
	n=read(),m=read(),p=read();
	for(int i=0;i<n;i++)
	{
		a[i]=read()%p;
		if(a[i]!=0&&f1==0) {c1=i; f1=1;}
	}
	for(int i=0;i<m;i++)
	{
		b[i]=read()%p;
		if(b[i]!=0&&f2==0) {c2=i; f2=1;}
	}
	cout<<c1+c2<<endl;
	return 0;
}