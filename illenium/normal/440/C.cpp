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

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll f[18],n;

int cal(ll x)
{
	int res,i=16;
	if(x<=11) return min(x,2+11-x);
	while(f[i-1]>=x) i--;
	res=((x/f[i-1])*(i-1))+cal(x%f[i-1]);
	if(x<f[i]-x) return res;
	return min(res,i+cal(f[i]-x));
}

int main()
{
	f[1]=1;
	for(int i=2;i<=16;i++) f[i]=10*f[i-1]+1;
	n=read();
	printf("%d",cal(n));
	return 0;
}