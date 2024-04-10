#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
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
struct node{char a,b;}p[maxn];

inline bool cmp(node a,node b)
{
	if(a.a==b.a) return a.b<b.b;
	return a.a<b.a;
}

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),cnt=0; scanf("%s",s+1); scanf("%s",t+1);
		int F=0;
		rep(i,1,n) if(s[i]>t[i]) {F=1; break;}
		if(F) {puts("-1"); continue;}
		rep(i,1,n) if(s[i]!=t[i]) p[++cnt].a=s[i],p[cnt].b=t[i];
		sort(p+1,p+cnt+1,cmp);
		int ans=0;
		rep(i,1,cnt)
		{
			if(p[i].a<p[i].b)
			{
				int f=cnt;
				rep(j,i+1,cnt)
				{
					if(p[j].a!=p[i].a) break;
					p[j].a=p[i].b;
				}
				sort(p+i+1,p+cnt+1,cmp);
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}