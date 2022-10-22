#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int main()
{
	ll n,m,a,ans,t1,t2;
	cin>>n>>m>>a;
	if(n%a==0) t1=n/a; else t1=n/a+1;
	if(m%a==0) t2=m/a; else t2=m/a+1;
	printf("%lld",t1*t2);
	return 0;
}