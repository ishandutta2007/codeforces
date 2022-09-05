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

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n=read();
		int ans=0;
		map<s64,s64>Map;
		int k=1;s64 b=0;
		auto ex=[&](s64 x)->bool
		{
			x=k*(x-b);
			auto it=Map.lower_bound(x+1);
			if(it==Map.begin())return 0;
			--it;
			return it->second>=x;
		};
		auto del=[&](s64 x)
		{
			x=k*(x-b);
			if(k==1)
			{
				while(!Map.empty())
				{
					auto it=--Map.end();
					if(it->second<x)break;
					if(it->first<x)
					{
						it->second=x-1;
						break;
					}
					Map.erase(it);
				}
			}
			else 
			{
				while(!Map.empty())
				{
					auto it=Map.begin();
					if(it->first>x)break;
					if(it->second>x)
					{
						s64 tmp=it->second;
						Map.erase(it);
						Map[x+1]=tmp;
						break;
					}
					Map.erase(it);
				}
			}
		};
		auto Ins=[&](s64 l,s64 r)
		{
			l=k*(l-b);r=k*(r-b);
			if(l>r)swap(l,r);
			Map[l]=r;
		};
		rep(tmp,1,n)
		{
			int x=read();
			if(x%2==0)
			{
				if(ex(x/2))
				{
					Map.clear();
					Ins(x/2,x/2);
					continue; 
				}
			}
			del(x);
			k*=-1;b=x-b;
			if(x%2==0)
			{
				if(!ex(x/2))Ins(x/2,x/2);
				++ans;
				continue;
			}
			if(!Map.empty())
			{
				++ans;
				continue;
			}
			ans+=2;
			Ins(1,x-1);
		}
		printf("%d\n",ans);
	}
}