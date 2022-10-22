#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int buf[22],top,f;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar(),f=1;
		while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
	}
	template<typename T>inline void write(T x)
	{
		if(x<0)putchar('-'),x=-x;
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
	}
}
using FastIO::read;
using FastIO::write;

int n,c,d,Con,leq=2e9,geq=-2e9;

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(c),read(d);
		if(d==1)geq=max(geq,1900-Con);
		else if(d==2)leq=min(leq,1899-Con);
		Con+=c;
	}
	if(leq<geq)return puts("Impossible"),0;
	if(leq>2e7)return puts("Infinity"),0;
	write(leq+Con);
	return 0;
}