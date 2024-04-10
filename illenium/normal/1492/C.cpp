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

char s[maxn],t[maxn];
int l[maxn],r[maxn],ans,n,m;

int main()
{
	n=read(); m=read(); scanf("%s",s+1); scanf("%s",t+1);
	int nw=1;
	rep(i,1,n) if(s[i]==t[nw]) l[nw]=i,nw++;
	nw=m;
	per(i,n,1) if(s[i]==t[nw]) r[nw]=i,nw--;
	rep(i,2,m) ans=max(ans,r[i]-l[i-1]);
	printf("%d\n",ans);
	return 0;
}