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

const int N=12,M=1e5+5;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int mat[N][M];
int n,m;
struct Arr
{
	int a[M];
	void init()
	{
		rep(i,1,m)a[i]+=a[i-1];
	}
	int query(int l,int r)
	{
		return a[r]-a[l-1];
	}
}up,le,face;
bool ban[N][M][4];
int rec_r[N*M],id[N][M],tot_id;

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
#endif
	int q;
	cin>>n>>m>>q;
	rep(i,1,n)
	rep(j,1,m)mat[i][j]=read();
	rep(i,1,n)
	rep(j,1,m)
	{
		if(mat[i][j]==mat[i-1][j])
		{
			++up.a[j];
			ban[i-1][j-1][3]=ban[i-1][j][2]=1;
		}
		if(mat[i][j]==mat[i][j-1])
		{
			++le.a[j];
			ban[i-1][j-1][1]=ban[i][j-1][0]=1;
		}
	}
	rep(i,1,n-1)
	rep(j,1,m-1)
	if(!id[i][j])
	{
		id[i][j]=++tot_id;
		deque<pii>q;
		q.push_back({i,j});
		int r=j;
		while(!q.empty())
		{
			int x,y;
			tie(x,y)=q.front();q.pop_front();
			chmax(r,y);
			if(x<=0 || x>=n || y<=0 || y>=m)
			{
				r=m;
				continue;
			}
			rep(d,0,3)
			if(!ban[x][y][d]){
				int x1=x+dx[d],y1=y+dy[d];
				if(!id[x1][y1]){
					id[x1][y1]=tot_id;
					q.push_back({x1,y1});
				}
			}
		}
		++face.a[r];
		rec_r[tot_id]=r;
	}
	
	up.init();
	le.init();
	face.init();
	while(q--)
	{
		int l=read(),r=read();
		int ans=n*(r-l+1)-up.query(l,r)-le.query(l+1,r)+face.query(l,r-1);
		static int last[N*M],t=0;
		++t;
		if(l>1)
		rep(x,1,n-1){
			int i=id[x][l-1];
			if(last[i]<t){
				last[i]=t;
				if(rec_r[i]>=l && rec_r[i]<r)
					--ans;
			}
		}
		printf("%d\n",ans);
	}
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/