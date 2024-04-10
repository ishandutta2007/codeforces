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

const int N=1000+5;
int p1[N],np1[N],p2[N],np2[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n;
	rep(i,1,n)np2[p2[i]=read()]=i;
	rep(i,1,n)np1[p1[i]=read()]=i;
	vector<pii>ans;
	for(;n>1;--n)
	{
		if(p1[n]==n&&p2[n]==n)continue;
		ans.push_back({n,p1[n]});
		ans.push_back({p2[n],n});
		int x=np1[n];
		np1[p1[x]=p1[n]]=x;
		x=np2[n];
		np2[p2[x]=p2[n]]=x;
	}
	printf("%d\n",int(ans.size())/2);
	rep(i,0,int(ans.size())/2-1)printf("%d %d %d %d\n",ans[i*2].first,ans[i*2].second,ans[i*2+1].first,ans[i*2+1].second);
}