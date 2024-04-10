#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=100500;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return q?n=-n:n;
}
int n,m;
int a[N];

int find(int q)
{
	fo(i,1,n)
	{
		if((i<q && a[q-i])&&(q+i<=n&&a[q+i]))return 1e9+10;
		if((i<q && a[q-i])||(q+i<=n&&a[q+i]))return i;
	}
	return 1e9+10;
}
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n),read(m);
		char ch=' ';
		for(;ch<'0'||ch>'9';ch=getchar());
		q=0;
		fo(i,1,n)
		{
			q+=(a[i]=ch-48);
			ch=getchar();
		}
		fo(i,1,n)
		{
			if(q==0)printf("0");
			else if(a[i])printf("1");
			else if(find(i)<=m)printf("1");
			else printf("0");
		}
		printf("\n");
	}



	return 0;
}