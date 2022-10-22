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

int n,k,a[maxn],s[maxn];
double ans;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=read(),s[i]=s[i-1]+a[i];
	for(int i=1;i+k-1<=n;i++)
		for(int j=i+k-1;j<=n;j++)
			ans=max(ans,(double)(s[j]-s[i-1])/(j-i+1));
	printf("%.8lf",ans);
	return 0;
}