#pragma GCC target("avx,avx2")	
#include<bits/stdc++.h>
#include<immintrin.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
char readc()
{
	char c;
	while(isspace(gc));
	return c;
}
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int U=1e5+5;
int v[U],g[U],ng[U],nex[U],fa[U];

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	int ans=0;
	while(n--)
	{
		int m=read();
		rep(i,1,m)v[i]=read();
		nex[v[1]]=1;
		rep(i,2,m)
		rep(j,v[i-1]+1,v[i])nex[j]=i;
		rep(i,1,m)g[i]=1e9;
		rep(tmp,1,U)
		{
			rep(i,1,m){fa[i]=i;ng[i]=-1;}
			per(i,m,1)
			{
				chmin(ng[i],g[i]);
				int vl=v[i]-g[i],vr=v[i]-ng[i]-1;		
				if(i>1&&vl<=v[i-1])
				{
					int j=vl<v[1]?1:nex[vl];
					while(j=find(j),j<i&&v[j]<=vr)
					{
						ng[j]=v[i]-v[j]-1;
						fa[j]=j+1;
					}
				}
				g[i]=ng[i];			
			}
			if(*max_element(g+1,g+m+1)<0){ans^=tmp;break;}
		}
	}
	puts(ans?"YES":"NO");
}