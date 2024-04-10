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

const int N=2e5+5,L=20,D=998244353;
vector<int>lk[2][N];
int n;
pii g[2][N];

pii operator -(pii a)
{
	return {-a.first,-a.second};
}
void pr_bfs()
{
	rep(j,0,1)
	rep(i,1,n)g[j][i]=pii(N,N);
	g[0][1]={0,0};
	priority_queue<pair<pii,int>>heap;
	heap.push({-g[0][1],1*2});
	while(!heap.empty())
	{
		auto pr=heap.top();heap.pop();
		int x=pr.second;
		int j=x%2;x/=2;
		pii now=g[j][x];
		//cerr<<j<<" "<<x<<endl;
		if(pr.first!=-now)continue;
		++now.second;
		for(auto y:lk[j][x])
		if(g[j][y]>now)
		{
			g[j][y]=now;heap.push({-g[j][y],y*2+j});
		}
		now=g[j][x];
		++now.first;
		if(g[j^1][x]>now)
		{
			g[j^1][x]=now;heap.push({-g[j^1][x],x*2+(j^1)});
		}
	}
}
void bfs()
{
	priority_queue<pair<pii,int>>heap;
	rep(i,1,n)
	{
		swap(g[0][i],g[1][i]);
		rep(j,0,1)
		{
			++g[j][i].first;			
			heap.push({-g[j][i],i*2+j});
		}
	}
	while(!heap.empty())
	{
		auto pr=heap.top();heap.pop();
		int x=pr.second;
		int j=x%2;x/=2;
		pii now=g[j][x];
		if(pr.first!=-g[j][x])continue;
		++now.second;
		for(auto y:lk[j][x])
		if(g[j][y]>now)
		{
			g[j][y]=now;heap.push({-g[j][y],y*2+j});
		}
		now=g[j][x];
		++now.first;
		if(g[j^1][x]>now)
		{
			g[j^1][x]=now;heap.push({-g[j^1][x],x*2+(j^1)});
		}
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int m;
	cin>>n>>m;
	rep(i,1,m)
	{
		int u=read(),v=read();
		lk[0][u].push_back(v);
		lk[1][v].push_back(u);
	}
	pr_bfs();
	pii gn=min(g[0][n],g[1][n]);
	//cout<<gn.first<<" "<<gn.second<<endl;
	if(gn.first>=L)
	{
		s64 ans=1;
		rep(i,1,gn.first)ans=ans*2%D;
		cout<<( (ans-1+gn.second)%D )<<endl;
		exit(0);
	}
	int ans=(1<<gn.first)-1+gn.second;
	while(gn.first<L)
	{
		bfs();
		gn=min(g[0][n],g[1][n]);
		chmin(ans,(1<<gn.first)-1+gn.second);
		//cout<<gn.first<<" "<<gn.second<<endl;
	}
	cout<<ans<<endl;
}