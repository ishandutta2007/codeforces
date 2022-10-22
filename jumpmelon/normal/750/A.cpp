#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int buf[22],top;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar(' ');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;

int n,k;

int main()
{
	read(n),read(k);
	k=240-k;
	for(int i=1;i<=n;i++)
	{
		if(k<5*i)return printf("%d",i-1),0;
		k-=5*i;
	}
	printf("%d",n);
	return 0;
}