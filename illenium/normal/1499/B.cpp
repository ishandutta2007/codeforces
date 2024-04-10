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
		scanf("%s",s+1); int len=strlen(s+1),f1=0,f2=0;
		rep(i,1,len-1) if(s[i]=='1'&&s[i+1]=='1') {f1=i; break;}
		per(i,len-1,1) if(s[i]=='0'&&s[i+1]=='0') {f2=i; break;}
		if(f2&&f1&&f2>f1) puts("NO"); else puts("YES");
	}
	return 0;
}