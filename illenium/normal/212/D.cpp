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
#define maxn 1000005
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

int n,l,r,x,top,a[maxn],sk[maxn];
double s[maxn];

int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n+1;i++)
	{
		while(a[i]<a[sk[top]])
		{
			l=sk[top]-sk[top-1];
			r=i-sk[top];
			s[1]+=x=a[sk[top--]];
			s[l+1]-=x;
			s[r+1]-=x;
			s[l+r+1]+=x;
		}
		sk[++top]=i;
	}
	for(int z=1;z<=2;z++) for(int i=1;i<=n;i++) s[i]+=s[i-1];
	for(int i=1;i<=n;i++) s[i]/=n-i+1;
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		printf("%.16lf\n",s[x]);
	}
	return 0;
}