#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 2500005
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

struct node{int w,id;}a[maxn];
struct node2{int a,b;};
int n,p[maxn];

inline bool operator < (node2 a,node2 b)
{
	if(a.a!=b.a) return a.a<b.a;
	return a.b<b.b;
}

map <int,vector <node2> > mp;

inline bool cmp(node a,node b){return a.w<b.w;}

int main()
{
	n=read(); int mx=0,F=0;
	rep(i,1,n) a[i].w=read(),a[i].id=i;
	
	if(n>2000)
	{
		sort(a+1,a+n+1,cmp);
		rep(i,2,n)
		{
			if(p[a[i].w-a[i-1].w]&&p[a[i].w-a[i-1].w]<i-1)
			{
				F=1; puts("YES"); int tmp=p[a[i].w-a[i-1].w];
				printf("%d %d %d %d\n",a[tmp-1].id,a[i].id,a[tmp].id,a[i-1].id); break;
			}
			else if(!p[a[i].w-a[i-1].w]) p[a[i].w-a[i-1].w]=i;
		}
		if(!F) puts("NO");
	}
	else
	{
		rep(i,1,n) rep(j,i+1,n) mp[a[i].w+a[j].w].pb({i,j});
		map <int,vector <node2> >::iterator it; int F=0;
		for(it=mp.begin();it!=mp.end();it++)
		{
			vector <node2> tmp=it->second;
			if(tmp.size()>=2)
			{
				for(int i=0;i<tmp.size();i++)
				{
					F=0;
					for(int j=0;j<tmp.size();j++)
					{
						if(tmp[i].a!=tmp[j].a&&tmp[i].a!=tmp[j].b&&
						tmp[i].b!=tmp[j].a&&tmp[i].b!=tmp[j].b)
						{
							puts("YES"); printf("%d %d %d %d\n",tmp[i].a,tmp[i].b,tmp[j].a,tmp[j].b);
							F=1; break;
						}
					}
					if(F) break;
				}
			}
			if(F) break;
		}
		if(!F) puts("NO");
	}
	return 0;
}