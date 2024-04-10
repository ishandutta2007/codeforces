#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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

ull h[maxn],h2[maxn],b[maxn];

inline ull gh(int l,int r,int opt)
{
	if(opt==1) return h[r]-h[l-1]*b[r-l+1];
	return h2[l]-h2[r+1]*b[r-l+1];
}

int main()
{
	b[0]=1; rep(i,1,maxn-5) b[i]=b[i-1]*233;
	int T=read();
	while(T--)
	{
		int F=0;
		scanf("%s",s+1); scanf("%s",t+1); ls=strlen(s+1); lt=strlen(t+1);
		ull tmp=0; rep(i,1,lt) tmp=tmp*233+t[i];
		rep(i,1,ls) h[i]=h[i-1]*233+s[i];
		per(i,ls,1) h2[i]=h2[i+1]*233+s[i];
		rep(i,1,ls) rep(j,i,ls)
		{
			if(gh(i,j,1)==tmp) F=1;
			per(k,j-1,1)
			{
				ull p=gh(i,j,1); int len=j-k; p*=b[len];
				p+=gh(k,j-1,0); if(p==tmp) {F=1;}
			}
		}
		if(F) puts("YES"); else puts("NO");
	}
	return 0;
}