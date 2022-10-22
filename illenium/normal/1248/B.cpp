#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
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

int a[maxn];

inline bool cmp(int x,int y){return x>y;}

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1,cmp);
	if(n%2==0)
	{
		ll t1=0,t2=0;
		for(int i=1;i<=(n/2);i++) t1+=a[i];
		for(int i=(n/2)+1;i<=n;i++) t2+=a[i];
		cout<<t1*t1+t2*t2;
	}
	else
	{
		ll t1=0,t2=0;
		for(int i=1;i<=(n/2)+1;i++) t1+=a[i];
		for(int i=(n/2)+2;i<=n;i++) t2+=a[i];
		cout<<t1*t1+t2*t2;
	}
	return 0;
}