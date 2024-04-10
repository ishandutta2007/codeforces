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
char readc()
{
	char c;
	while(gc<'-');
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

const int N=200+5,T=20+5,W=1e6+5;
const char char_dir[]="NSEWC";
const int dx[]={-1,1,0,0,0},dy[]={0,0,1,-1,0};
int char_dy_dir[128];
char s[W];int nex[W][5];	
bool valid[N][N];
int g[N][N];
struct Supply
{
	int x,y,t,mn;
}supply[T];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif	
	int n,m;
	cin>>n>>m;
	int k,t,w;
	cin>>k>>t>>w;
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			char c=readc();
			if(c=='L')continue;
			valid[i][j]=1;
			if(c=='M')supply[0]={i,j,0};
			else 
			if(c=='P')supply[t+1]={i,j,w};
		}
	}
	rep(i,1,w)s[i]=readc();
	rep(i,0,4)char_dy_dir[(int)char_dir[i]]=i;
	rep(j,0,4)nex[w+1][j]=w+1;
	per(i,w,1)
	{
		rep(j,0,4)nex[i][j]=nex[i+1][j];
		nex[i][char_dy_dir[(int)s[i]]]=i;
	}

	rep(i,1,t)
	{
		supply[i].x=read()+1;
		supply[i].y=read()+1;
		supply[i].t=read();
	}
	sort(supply+1,supply+t+1,[&](const Supply &a,const Supply &b){return a.t<b.t;});
	while(t&&supply[t].t>w)
	{
		supply[t]=supply[t+1];
		--t;
	}
	rep(i,1,t+1)supply[i].mn=supply[i].t+1;

	rep(i,0,t)
	if(supply[i].mn<=supply[i].t&&valid[supply[i].x][supply[i].y])
	{
		int limit=min(w+1,supply[i].t+k+1);
		rep(x,1,n)
		rep(y,1,m)g[x][y]=limit;
		priority_queue<int>heap;
		auto push=[&](int x,int y,int t)
		{
			if(g[x][y]>t)
			{
				g[x][y]=t;
				heap.push(-(t*N*N+x*N+y));
			}			
		};
		push(supply[i].x,supply[i].y,supply[i].t);
		while(!heap.empty())
		{
			int t=-heap.top();heap.pop();
			int y=t%N;t/=N;	
			int x=t%N;t/=N;
			if(t!=g[x][y])continue;
			rep(dir,0,4)
			{
				int t1=nex[t+1][dir];
				if(t1>=limit)continue;
				int x1=x+dx[dir],y1=y+dy[dir];
				if(valid[x1][y1])
				{
					rep(dir1,0,4)
					{
						int x2=x1+dx[dir1],y2=y1+dy[dir1];
						if(valid[x2][y2])push(x2,y2,t1);	
					}
				}
				else 
				{
					rep(dir1,0,4)
					{
						x1=x+dx[dir1];y1=y+dy[dir1];
						if(valid[x1][y1])
						{
							int x2=x1+dx[dir],y2=y1+dy[dir];
							if(valid[x2][y2])push(x2,y2,t1);	
						}
					}
				}
			}
		}
		rep(j,i+1,t+1)
		if(g[supply[j].x][supply[j].y]<limit)
			chmin(supply[j].mn,g[supply[j].x][supply[j].y]);
	}

	if(supply[t+1].mn>w)puts("-1");
	else printf("%d\n",supply[t+1].mn);
}