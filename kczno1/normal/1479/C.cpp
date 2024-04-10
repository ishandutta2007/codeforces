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

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int l,r;
	cin>>l>>r;
	r-=l;
	puts("YES");
	if(r==0)
	{
		printf("2 1\n1 2 %d\n",l);
		exit(0);
	}
	if(r==1)
	{
		printf("3 3\n1 2 %d\n1 3%d\n2 3 %d\n",l,l+1,1);
		exit(0);
	}
	int n=0;
	while(r>>n)++n;
	vector<pair<pii,int>>edges;
	int N=n+2;
	auto F=[&](int x)
	{
		if(x==n-1)return 1;
		return n-x+1;
	};
	auto add=[&](int x,int y,int w)
	{
		edges.push_back({{x,y},w});
	};
	rep(i,0,n-1)add(F(i),N,l);
	add(1,2,1<<(n-2));
	add(2,N,l+r-(1<<(n-2)));
	rep(i,0,n-1)
	rep(j,0,i-1)
		add(F(i),F(j),1<<j);
	rep(i,0,n-2)
	if((r>>i)&1)
		add(2,F(i),(r&~((1<<(i+1))-1))-(1<<(n-2)));
	printf("%d %d\n",N,int(edges.size()));
	for(auto e:edges)printf("%d %d %d\n",e.first.first,e.first.second,e.second);
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/