#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

char a[maxn],b[maxn],c[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",a+1); scanf("%s",b+1); scanf("%s",c+1);
		int len=strlen(a+1),f=0;
		for(int i=1;i<=len;i++)
		{
			if(a[i]==c[i]||b[i]==c[i]) continue;
			else f=1;
		}
		if(f==1) puts("NO");
		else puts("YES");
	}
	return 0;
}