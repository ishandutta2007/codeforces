#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char s[maxn],t[maxn];
int ls,lt;

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1); scanf("%s",t+1); ls=strlen(s+1); lt=strlen(t+1);
		int nw=lt;
		for(int i=ls;i>=1;i--)
		{
			if(s[i]==t[nw])
			{
				nw--;
				if(nw==0) break;
				continue;
			}
			i--;
		}
		if(nw==0) puts("YES"); else puts("NO");
	}
	return 0;
}