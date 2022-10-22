#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define ins insert
#define pb push_back
#define vi vector <int>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char s[maxn];
int a[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1); int len=strlen(s+1);
		rep(i,1,len) a[i]=s[i]-'0';
		int F=1;
		per(i,len-1,1) if(a[i]+a[i+1]>=10) {F=i; break;}
		rep(i,1,F-1) printf("%d",a[i]); printf("%d",a[F]+a[F+1]);
		rep(i,F+2,len) printf("%d",a[i]);
		puts("");
	}
	return 0;
}