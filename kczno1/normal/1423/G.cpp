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

const int N=1e5+5;
int n;	
map<int,int> Map_A;
map<int,map<int,int>> Map_V;
namespace BIT
{
//kx+b	
s64 s0[N],s1[N];//sum_b,sum_k
void A(int i,int k,int b)
{
	for(;i<=n;i+=i&-i)
	{
		s1[i]+=k;
		s0[i]+=b;
	}
}
void add(int l,int r,int k,int b)
{
	if(l>r)return ;
	A(l,k,b);
	A(r+1,-k,-b);
}
s64 query(int x)
{
	s64 k=0,b=0;
	for(int i=x;i;i-=i&-i){k+=s1[i];b+=s0[i];}
	return k*x+b;
}
};

void add_ij(int i,int j,int w)
{
	assert(j<i);
	int mn=n-i+1,mx=i-j;
	if(mx<mn)swap(mn,mx);
	BIT::add(mx,n-j,-1*w,(n-j+1)*w);
	BIT::add(mn,mx-1,0,mn*w);
	BIT::add(1,mn-1,1*w,0);
}
void add_lr(int l,int r,int w)
{
	++l;
	if(l>r)return ;
	BIT::add(1,n-r+1,0,(r-l+1)*w);
	BIT::add(n-r+2,n-l+1,-1*w,(n-l+1+1)*w);
}
void ins(map<int,int> &Map,int l,int r)
{
	auto it=Map.lower_bound(l);
	int r1=0,l1=0;
	if(it!=Map.end())
		add_ij(r1=it->first,r,1);		
	if(it!=Map.begin())
		l1=(--it)->second;

	add_ij(l,l1,1);
	if(r1)add_ij(r1,l1,-1);

	add_lr(l,r,1);
	Map[l]=r;
}
void del(map<int,int> &Map,int l,int r)
{
	auto split=[&](int p)
	{
		auto it=Map.lower_bound(p);
		if(it==Map.begin())return ;
		--it;
		if(it->second>=p)
		{
			Map[p]=it->second;
			it->second=p-1;
		}
	};
	split(l);split(r+1);
	
	auto it=Map.lower_bound(l);
	if(it==Map.end())
	{
		cerr<<"it==Map.end() "<<l<<" "<<r<<endl;
		for(auto p:Map)cerr<<p.first<<" "<<p.second<<endl;
		assert(0);
	}
	if(it->second!=r)
	{
		cerr<<"it->second!=r "<<l<<" "<<it->second<<" "<<r<<endl;
		assert(0);
	}
	Map.erase(it);

	int l1=0,r1=0;	
	it=Map.lower_bound(r+1);
	if(it!=Map.end())
		add_ij(r1=it->first,r,-1);	
	if(it!=Map.begin())
		l1=(--it)->second;
	add_ij(l,l1,-1);
	if(r1)add_ij(r1,l1,1);

	add_lr(l,r,-1);
}
void split(int p)//split p-1 and p
{
	auto it=Map_A.lower_bound(p);
	if(it->first==p)return ;
	--it;
	Map_A[p]=it->second;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	n=read();int m=read();
	rep(i,1,n)
	{
		int x=read();
		ins(Map_V[x],i,i);
		Map_A[i]=x;
	}
	Map_A[n+1]=0;
	while(m--)
	if(read()==1)
	{
		int l=read(),r=read(),x=read();
		split(l);split(r+1);
		auto it=Map_A.lower_bound(l);
		while(it->first<=r)
		{
			auto it1=it;
			++it1;
			//cerr<<it->second<<endl;
			del(Map_V[it->second],it->first,it1->first-1);
			Map_A.erase(it);
			it=it1;
		}
		Map_A[l]=x;
		ins(Map_V[x],l,r);
	}
	else 
	{
		printf("%lld\n",BIT::query(read()));
	}
}