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

char s[maxn];
int p[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1); int len=strlen(s+1),ans=0;
		for(int i=1;i<=len;i++)
		{
			if(s[i]=='L') p[i]=p[i-1]+1;
			else p[i]=0; ans=max(ans,p[i]);
		}
		printf("%d\n",ans+1);
	}
	return 0;
}