//#pragma GCC target("avx,avx2")	
#include<bits/stdc++.h>
//#include<immintrin.h>
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

const int N=3e5+5;
vector<int>lk[N],ans;
bool mark[N],vis[N];

void dfs(int x)
{
	vis[x]=1;
	if(!mark[x])
	{
		ans.push_back(x);
		mark[x]=1;
		for(auto y:lk[x])mark[y]=1;
	}
	for(auto y:lk[x])
	if(!vis[y])
		dfs(y);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt=read();
	while(tt--)
	{
		int n=read(),m=read();
		rep(i,1,n){lk[i].clear();mark[i]=vis[i]=0;}
		rep(i,1,m)
		{
			int x=read(),y=read();
			lk[x].push_back(y);
			lk[y].push_back(x);
		}
		ans.clear();
		dfs(1);
		rep(i,1,n)
		if(!vis[i])ans.clear();
		if(ans.empty())puts("NO");
		else 
		{
			puts("YES");
			printf("%d\n",int(ans.size()));
			for(auto x:ans)printf("%d ",x);puts("");
		}
	}
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/