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

const int INF=1e9;

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	vector<pii>edges(m);
	vector<vector<int>>dis(n,vector<int>(n,INF));	
	rep(i,0,n-1)dis[i][i]=0;
	rep(e_id,0,m-1)
	{
		int i=read()-1,j=read()-1,b=read();
		edges[e_id]={i,j};
		if(b)
		{
			dis[i][j]=1;dis[j][i]=-1;
		}		
		else 
		{
			dis[i][j]=1;dis[j][i]=1;
		}
	}
	rep(k,0,n-1)
	rep(i,0,n-1)
	{
		rep(j,0,n-1)chmin(dis[i][j],dis[i][k]+dis[k][j]);
		if(dis[i][i]<0){puts("NO");exit(0);}
	}
	pii mx={-1,0};
	rep(i,0,n-1)
	rep(j,0,n-1)chmax(mx,{dis[i][j],i});
	int x=mx.second;
	for(auto e:edges)
	if(dis[x][e.first]==dis[x][e.second])
	{
		puts("NO");
		exit(0);
	}
	puts("YES");
	cout<<mx.first<<endl;
	rep(i,0,n-1)printf("%d%c",dis[x][i]," \n"[i==n-1]);
}