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
#define maxn 500005
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

int n,k,d,l,a[maxn],dp[maxn],has[maxn];

int main()
{
	n=read(); k=read(); d=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	dp[0]=has[0]=1;
	for(int i=1;i<=n;i++)
	{
		while(l<=i-k&&a[i]-a[l+1]>d) l++;
		if(i>=k&&l+k<=i&&has[i-k]-has[l-1]>=1) dp[i]=1;
		has[i]=has[i-1]+dp[i];
	}
	if(dp[n]) puts("YES");
	else puts("NO");
	return 0;
}