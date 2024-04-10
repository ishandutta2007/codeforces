#include<iostream>
using namespace std;
int read()
{
     int x=0,f=1;
     char ch;
     while(ch<'0'||ch>'9')  {if(ch=='-')f=-1;ch=getchar();}
     while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
     return f*x;
}
void write(long long x) 
{
	if (x < 0) 
	{ 
    	x = -x;
    	putchar('-');
	}
	if (x > 9) write(x / 10);  
	putchar(x % 10 + '0');  
}
void doit(int ax,int bx,int k)
{
	int a[200006],b[200006];
	int heada[200006]={},headb[200006]={};
	long long answer=0;
	for(int i=1;i<=k;i++)
		a[i]=read();
	for(int i=1;i<=k;i++)
		b[i]=read();
	for(int i=1;i<=k;i++)
	{
		heada[a[i]]++;
		headb[b[i]]++;
	}
	int s=k;
	for(int i=1;i<=s;i++)
	{
		k--;
		answer+=k+2-heada[a[i]]-headb[b[i]];
		heada[a[i]]--;
		headb[b[i]]--;
	}
	write(answer);
	putchar('\n');
}
int main()
{
	int n,k,ax,bx;
	n=read();
	for(int i=1;i<=n;i++)
	{
		ax=read();
		bx=read();
		k=read();
		doit(ax,bx,k);
	}
	return 0;
	
}