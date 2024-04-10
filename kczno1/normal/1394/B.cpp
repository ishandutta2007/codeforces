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

const int N=2e5+5;
int n,m,k;
vector<pii>lk0[N];
vector<int>lk1[100],lk2[100];
bool mark[N];
int ans,cnt[100];

void dfs(int x,int y)
{
	if(x>k){++ans;return ;}
	int i=(x-1)*10+y-1;
	if(!cnt[i])
	{
		for(auto j:lk2[i])++cnt[j];
		dfs(x+1,1);
		for(auto j:lk2[i])--cnt[j];
	}
	if(y<x)dfs(x,y+1);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
/*	int x=1;
	rep(i,1,9)x*=i;
	cerr<<x<<endl;*/
	cin>>n>>m>>k;
	rep(i,1,m)
	{
		int u=read(),v=read(),w=read();
		lk0[u].push_back(pii(w,v));
	}	
	rep(x,1,n)
	{
		sort(lk0[x].begin(),lk0[x].end());
		int c=lk0[x].size();
		rep(i,0,c-1)
			lk1[(c-1)*10+i].push_back(lk0[x][i].second);
	}
	rep(i,0,99)
	if(lk1[i].size())
	{
		for(auto x:lk1[i])
		{
			if(mark[x])++cnt[i];
			mark[x]=1;
		}
		rep(j,i+1,99)
		for(auto x:lk1[j])
		if(mark[x])
		{
			//cerr<<i<<" "<<j<<endl;
			lk2[i].push_back(j);
			break;
		}
		for(auto x:lk1[i])mark[x]=0;
	}
	dfs(1,1);
	cout<<ans;
}