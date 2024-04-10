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

const int N=2e5+5,D=998244353;
int a[N],b[N],pre[N],nex[N];
bool ap[N];

void del(int x)
{
	int l=pre[x],r=nex[x];
	nex[l]=r;pre[r]=l;
}
int work()
{
	int n=read(),k=read();
	rep(i,1,n){a[i]=read();ap[i]=0;nex[pre[a[i]]=a[i-1]]=a[i];}
	nex[a[n]]=0;
	rep(i,1,k)ap[b[i]=read()]=1;
	int ans=1;
	rep(i,1,k)
	{
		int x=b[i];ap[x]=0;
		int l=pre[x],r=nex[x];
		int c=0;
		if(l&&!ap[l])
			++c;
		if(r&&!ap[r])
			++c;
		ans=ans*c%D;
		del(x);
	}
	return ans;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int case_cnt=read();
	rep(case_id,1,case_cnt)printf("%d\n",work());	
}