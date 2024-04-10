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
int v[30];

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1); int len=strlen(s+1),cnt=0,F=0;
		rep(i,1,len) if(!v[s[i]-'a']) cnt++,v[s[i]-'a']=1;
		rep(i,1,cnt) if(v[s[i]-'a']!=1) {F=1; break;} else v[s[i]-'a']++;
		rep(i,cnt+1,len) if(s[i]!=s[i-cnt]) {F=1; break;}
		if(F) puts("NO"); else puts("YES");
		rep(i,0,25) v[i]=0;
	}
	return 0;
}