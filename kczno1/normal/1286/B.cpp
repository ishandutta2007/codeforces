#include<bits/stdc++.h>
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

const int N=2000+5;
int a[N],q[N],tot,c[N];
vector<int>lk[N];

void dfs(int x)
{
	int l=++tot;q[l]=x;
	int r=l;
	for(auto y:lk[x])
	{
		dfs(y);
		int del=r-l;
		while(r<tot)
		{
			++r;
			a[q[r]]+=del; 
		}
	}
	if(c[x]>r-l)
	{
		puts("NO");
		exit(0);
	}
	a[x]=c[x]+1;
	rep(i,l+1,r)a[q[i]]+=a[q[i]]>=c[x]+1;
} 

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	rep(i,1,n){lk[read()].push_back(i);c[i]=read();}
	dfs(lk[0][0]);
	puts("YES");
	rep(i,1,n)printf("%d ",a[i]);
}