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
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define pb push_back
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

const int N=2e5+5;
int n,m;
pii edge[N];
u64 ans[N];
int in_3c[N][3];//cnt that appear in 3-circle
namespace GET_IN_3C
{
int du[N];
vector<int>lk[N];
bool in[N];
bool da(int x,int y)
{
	return du[x]!=du[y]?du[x]>du[y]:x>y;
}
void main()
{
	rep(i,1,m){++du[edge[i].first];++du[edge[i].second];}
	rep(i,1,m)
	{
		int x=edge[i].first,y=edge[i].second;
		if(!da(x,y))swap(x,y);
		lk[x].push_back(y);
	}
	rep(x,1,n)
	{
		for(auto y:lk[x])in[y]=1;
		for(auto y:lk[x])
		{
			for(auto z:lk[y])
			if(in[z])
			{
				int a=x,b=y,c=z;
				if(b<a)swap(a,b);
				if(c<b)swap(c,b);
				if(b<a)swap(a,b);
				++in_3c[a][0];	
				++in_3c[b][1];	
				++in_3c[c][2];	
			}
		}
		for(auto y:lk[x])in[y]=0;
	}
}
};
vector<int>lkl[N],lkr[N];
void init_lk()
{
	rep(x,1,n){lkl[x].clear();lkr[x].clear();}
	rep(i,1,m)
	{
		int l=edge[i].first,r=edge[i].second;
		if(l>r)swap(l,r);
		lkr[l].push_back(r);
		lkl[r].push_back(l);
	}
}
namespace SOLVE1
{
int s[N];
void main()
{
	init_lk();
	rep(x,1,n)ans[x]=u64(x-1-lkl[x].size())*(n-x-lkr[x].size());
	rep(i,1,m)
	{
		int l=edge[i].first,r=edge[i].second;
		if(l>r)swap(l,r);
		++s[l+1];--s[r];
	}
	rep(i,1,n)s[i]+=s[i-1];
	rep(x,1,n)ans[x]-=s[x];
	rep(x,1,n)
	{
		sort(lkl[x].begin(),lkl[x].end());
		rep0(i,0,lkl[x].size())ans[lkl[x][i]]+=i;
		sort(lkr[x].begin(),lkr[x].end(),greater<int>());
		rep0(i,0,lkr[x].size())ans[lkr[x][i]]+=i;
	}
}
};
namespace SOLVE0
{
int s[N];
void main()
{
	init_lk();
	rep(x,1,n)
	{
		int c=n-x-lkr[x].size();
		ans[x]=u64(c)*(c-1)/2;
	}
	per(x,n,1)s[x]=s[x+1]+lkr[x].size();
	rep(x,1,n)ans[x]-=s[x+1];
	rep(x,1,n)
	{
		sort(lkl[x].begin(),lkl[x].end(),greater<int>());
		rep0(i,0,lkl[x].size())ans[lkl[x][i]]+=i+lkr[x].size();
	}
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int a,b,c;
	cin>>n>>m>>a>>b>>c;
	rep(i,1,m)edge[i]=pii(read()+1,read()+1);

	GET_IN_3C::main();		

	SOLVE1::main();
	u64 ans=0,sum=0;
	rep(x,1,n)sum+=(x-1)*(::ans[x]-in_3c[x][1]);
	ans+=b*sum;

	SOLVE0::main();
	sum=0;
	rep(x,1,n)sum+=(x-1)*(::ans[x]-in_3c[x][0]);
	ans+=a*sum;

	rep(i,1,m)edge[i]=pii(n-edge[i].first+1,n-edge[i].second+1);
	SOLVE0::main();
	sum=0;
	rep(x,1,n)sum+=(x-1)*(::ans[n-x+1]-in_3c[x][2]);
	ans+=c*sum;

	cout<<ans;
}