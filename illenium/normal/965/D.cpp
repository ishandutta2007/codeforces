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

int n,l,a[maxn],s[maxn];

int main()
{
	n=read(); l=read();
	for(int i=1;i<n;i++) a[i]=read(),s[i]=s[i-1]+a[i];
	int ans=1e9;
	for(int i=l;i<n;i++) ans=min(ans,s[i]-s[i-l]);
	cout<<ans;
	return 0;
}