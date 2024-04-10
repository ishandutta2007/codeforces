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

int Q(int p)
{
	printf("? %d\n",p+1);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
void O(int p)
{
	printf("! %d\n",p+1);
	fflush(stdout);
	exit(0);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,k;
	cin>>n>>k;
	int p,x;
	mt19937 rng(time(0));
	while(1)
	{
		p=rng()%n;
		x=Q(p);
		if(x<k)break;
	}	
	if(x<k)
	{
		int i=0;
		while(1)
		{
			int p1=(p+(1<<i))%n;
			x=Q(p1);
			if(x==k)O(p1);
			if(x>k)break;
			++i;
		}
		while(1)
		{
			--i;
			chmax(i,0);
			int p1=(p+(1<<i))%n;
			x=Q(p1);
			if(x==k)O(p1);
			if(x<k)p=p1;
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