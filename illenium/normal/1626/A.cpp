#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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
int cnt[50];

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1); int n=strlen(s+1);
		rep(i,1,n) cnt[s[i]-'a']++;
		rep(i,0,25) rep(j,1,cnt[i]) printf("%c",'a'+i);
		
		rep(i,0,25) cnt[i]=0; puts("");
	}
	return 0;
}