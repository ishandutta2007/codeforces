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

int n,a[105],len[105],ans;

int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	ans=unique(a+1,a+n+1)-a;
	if(a[1]==0) cout<<ans-2;
	else cout<<ans-1;
	return 0;
}