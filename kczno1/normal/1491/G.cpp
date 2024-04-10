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

const int N=2e5+5;
int c[N],n;
bool vis[N];
vector<pii> ans;
void C(int x,int y)
{
	ans.push_back({x,y});
	swap(c[x],c[y]);
}
void merge(int x,int y)
{
	while(c[x]!=y)
		C(x,c[x]);
	while(c[y]!=x)
		C(y,c[y]);
	C(x,y);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n;
	rep(i,1,n)
		c[i]=read();
	int last=0,one=0;
	rep(i,1,n)
	if(!vis[i])
	{
		if(c[i]==i)
		{
			one=i;
			continue;
		}
		for(int j=i;!vis[j];j=c[j])vis[j]=1;
		if(last){C(last,i);merge(last,i);last=0;one=i;}
		else last=i;
	}
	if(last)
	{
		if(one)
		{
			C(last,one);
			merge(last,one);
		}
		else 
		{
			int x=last,y=c[x],z=c[y];
			C(x,y);
			C(y,z);
			merge(x,y);
		}
	}
	printf("%d\n",int(ans.size()));
	for(auto [x,y]:ans)printf("%d %d\n",x,y);
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase, fa[++tot]=tot(UB)  
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/