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

const int N=3e5+5;
int p[N],np[N];
vector<pii>ans;
void P(int x,int y)
{
	ans.push_back({x,y});
	swap(p[x],p[y]);
	swap(np[p[x]],np[p[y]]);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	rep(i,1,n)np[p[i]=read()]=i;
	rep(y,1,n)
	{
		int x=np[y];
		if(x==y)continue;
		if(abs(x-y)>=n/2)
		{
			P(x,y);
			continue;
		}
		int k;
		if(x-1>=n/2)k=1; 
		else k=n;
		P(x,k);
		if(abs(y-k)>=n/2)P(y,k);
		else
		{
			if(y-1>=n/2){P(y,1);P(1,k);P(y,1);}
			else{P(y,n);P(n,k);P(y,n);}
		}
		P(x,k);
	}
	rep(i,1,n)assert(p[i]==i&&np[i]==i);
	printf("%d\n",int(ans.size()));
	for(auto p:ans)printf("%d %d\n",p.first,p.second);
}