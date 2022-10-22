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

void write(int x)
{
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

const int p1=100019;
const int p2=7;


int main()
{
	int n,m;
	n=read(); m=read();
	int last=p1,cnt=n-1;
	if(n==2)
	{
		puts("100019 100019");
		puts("1 2 100019");
		return 0;
	}
	printf("7 100019\n");
	for(int i=2;i<=n-2;i++) printf("1 %d %d\n",i,1);
	printf("1 %d %d\n",n-1,100015-n);
	printf("1 %d 7\n",n);
	if(m==n-1) return 0;
	for(int i=2;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			printf("%d %d 10000000\n",i,j);
			cnt++;
			if(cnt==m) return 0;
		}
	}
	return 0;
}