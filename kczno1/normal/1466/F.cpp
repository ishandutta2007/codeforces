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

const int N=5e5+5,D=1e9+7;
int fa[N];
bool full[N];
int find(int x)
{
	if(x==fa[x])return x;
	int f1=find(fa[x]);
	return fa[x]=f1;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read(),m=read();	
	rep(i,1,m)fa[i]=i;
	vector<int>ans;
	s64 prod=1;
	rep(i,1,n)
	{
		if(read()==1)
		{
			int x=read();
			x=find(x);
			if(full[x])continue;
			full[x]=1;
		}
		else 
		{
			int x=read(),y=read();
			int fx=find(x),fy=find(y);
			if(fx==fy)
			{
				continue;
			}
			else 
			{
				if(full[fx] && full[fy])continue;
				fa[fx]=fy;
				full[fy]|=full[fx];
			}
		}
		ans.push_back(i);
		prod=prod*2%D;
	}
	cout<<prod<<" "<<ans.size()<<endl;
	for(auto x:ans)printf("%d ",x);
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/