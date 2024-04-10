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

const int N=1e5+5;
int a[N],h[N],st2[N],st3[N],t2,t3;

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n;
	rep(i,1,n)a[i]=read();
	vector<pii>ans;
	int nh=n+1;
	per(i,n,1)
	if(a[i]==1)
	{
		h[i]=--nh;
		st2[++t2]=i;
		ans.push_back({i,h[i]});
	}
	else 
	if(a[i]==2)
	{
		if(!t2){puts("-1");exit(0);}
		h[i]=h[st2[t2--]];
		st3[++t3]=i;
		ans.push_back({i,h[i]});
	}
	else 
	if(a[i]==3)
	{
		if(!t2&&!t3){puts("-1");exit(0);}
		h[i]=--nh;
		ans.push_back({i,h[i]});
		int j;
		if(t3)j=st3[t3--];
		else j=st2[t2--];
		ans.push_back({j,h[i]});
		st3[++t3]=i;
	}
	printf("%d\n",int(ans.size()));
	for(auto p:ans)printf("%d %d\n",p.second,p.first);
}