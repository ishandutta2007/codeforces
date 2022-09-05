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

vector<pair<s64,s64>>ans;
s64 SUM(s64 x,s64 y)
{
	ans.push_back(make_pair(x,y*2));
	return x+y;
}
s64 XOR(s64 x,s64 y)
{
	ans.push_back(make_pair(x,y*2+1));
	return x^y;
}
s64 MUL(s64 x,s64 y)
{
	assert(x>0&&y>0);
	s64 ans=x;--y;
	while(y)
	{
		if(y&1)ans=SUM(ans,x);
		x=SUM(x,x);y>>=1;
	}
	return ans;
}
void exgcd(s64 &a,s64 &b,s64 x,s64 y)
{
	if(y==0)
	{
		assert(x==1);
		a=1;b=0;
		return ;
	}
	exgcd(b,a,y,x%y);
	b-=x/y*a;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	s64 x;
	cin>>x;
	s64 y=x;
	while(__builtin_popcount(y&x)!=1)y=SUM(y,y);
	y=XOR(x,y);
	x=SUM(x,x);
	assert(__gcd(x,y)==1);
	s64 a,b;
	exgcd(a,b,x,y);
	//cerr<<a<<" "<<b<<" "<<x<<" "<<y<<endl;
	if(a>0)
	{
		a-=y;b+=x;
	}
	assert(a<0&&b>0);
	assert(XOR(MUL(x,-a),MUL(y,b))==1);

	printf("%d\n",int(ans.size()));
	for(auto pr:ans)printf("%lld %c %lld\n",pr.first,"+^"[pr.second%2],pr.second/2);
	//printf("%d\n",(798)^155);
}