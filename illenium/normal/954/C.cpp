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

void write(int x)
{
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

int a[maxn];

int main()
{
	//freopen("CF954C.in","r",stdin);
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int r=1000000000,c=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			puts("NO");
			return 0;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(fabs(a[i]-a[i-1])==1) continue;
		else
		{
			if(c==0) c=fabs(a[i]-a[i-1]);
			else if(fabs(a[i]-a[i-1])==c) continue;
			else
			{
				puts("NO");
				return 0;
			}
		}
	}
	if(c==0) c=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]%c==0&&a[i+1]==a[i]+1&&c!=1)
		{
			puts("NO");
			return 0;
		}
		else if(a[i]%c==1&&a[i+1]==a[i]-1&&c!=1)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	cout<<r<<" "<<c<<endl;
	return 0;
}