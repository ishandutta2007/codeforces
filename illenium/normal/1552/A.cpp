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

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(); scanf("%s",s+1); rep(i,1,n) t[i]=s[i];
		sort(t+1,t+n+1); int ans=0;
		rep(i,1,n) if(s[i]!=t[i]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}