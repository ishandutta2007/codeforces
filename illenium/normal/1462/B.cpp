#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
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

char s[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),F=0; scanf("%s",s+1);
		if(s[1]=='2'&&s[2]=='0'&&s[3]=='2'&&s[4]=='0') F=1;
		if(s[1]=='2'&&s[2]=='0'&&s[3]=='2'&&s[n]=='0') F=1;
		if(s[1]=='2'&&s[2]=='0'&&s[n-1]=='2'&&s[n]=='0') F=1;
		if(s[1]=='2'&&s[n-2]=='0'&&s[n-1]=='2'&&s[n]=='0') F=1;
		if(s[n-3]=='2'&&s[n-2]=='0'&&s[n-1]=='2'&&s[n]=='0') F=1;
		if(F) puts("YES"); else puts("NO");
	}
	return 0;
}