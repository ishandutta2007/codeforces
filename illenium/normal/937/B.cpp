#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
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

int p,y,prime[maxn],cnt,flag[maxn];

bool isprime(int x)
{
	for(int i=2;i<=min(p,(int)sqrt(y));i++)
	{
		if(x%i==0) return false;
		else continue;
	}
	return true;
}

int main()
{
	p=read(); y=read();
	for(int i=y;i>p;i--)
	{
		if(isprime(i)) {cout<<i; return 0;}
		else continue;
	}
	cout<<"-1";
	return 0;
}