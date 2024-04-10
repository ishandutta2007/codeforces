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

const int N=1e6+5,D=1e9+7;
int p[N];
bool mark[N];
void work()
{
	int n=read();
	rep(i,1,n){p[i]=read();mark[i]=0;}
	int ans2=0;
	s64 ans1=1;
	int m=n;
	while(m>4)
	{
		ans1=ans1*3%D;
		m-=3;
	}
	ans1=ans1*m%D;
	bool flag=0;
	int cnt[2]={};//cnt of sz=1,2
	rep(i,1,n)
	if(!mark[i])
	{
		int sz=0;
		for(int j=i;!mark[j];j=p[j])
		{
			mark[j]=1;
			++sz;
		}
		while(sz>4)
		{
			++ans2;sz-=3;
		}
		if(sz==4)
		{
			++ans2;++cnt[0];flag=1;
		}
		else 
		if(sz==2)++cnt[1];
		else 
		if(sz==1)++cnt[0];
	}
	if(m==4)
	{
		if(cnt[1]-cnt[0]>=2)cnt[1]-=2;
		else if(flag){--ans2;--cnt[0];}
		else if(cnt[1]>=2)cnt[1]-=2;
		else 
		{ 
			if(cnt[1]) 
			{
				assert(cnt[0]>=2);
				ans2++;
				--cnt[1];cnt[0]-=2;
			}
			else 
			{
				if(cnt[0]>=4)
				{
					ans2+=2;
					cnt[0]-=4;
				}
				else 
				{
					ans2++;
					--cnt[0];
				}
			}
		}
	}
	else 
	if(m==2)
	{
		if(cnt[1])--cnt[1];
		else 
		{
			cnt[0]-=2;ans2++;
		}
	}
	while(cnt[0]&&cnt[1])
	{
		ans2++;--cnt[0];--cnt[1];
	}
	ans2+=cnt[0]/3*2+cnt[1];
	cout<<ans1<<" "<<ans2<<endl;
}
int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt=read();
	while(tt--)work();	
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/