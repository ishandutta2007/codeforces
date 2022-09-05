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

namespace BING
{
const int N=400+5;
int fa[N];
void init()
{
	rep(i,1,N-1)fa[i]=i;
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(const pii &e)
{
	fa[find(e.first)]=find(e.second);
}
bool con(const pii &e)
{
	return find(e.first)==find(e.second);
}
};
const int N=20+5,M=400*2+5;
char s[N][N];int n1,n2,m;
pii e[M];bool in[M],lk[M][M];int g[M],q[M],fr[M],tail;

int leave[N*N];
void leave_add(int i,int w)
{
	leave[e[i].first]+=w;leave[e[i].second]+=w;
}
void leave_init()
{
	rep(i,1,n1)
	rep(j,1,n2)leave[(i-1)*n2+j]=(i+j)%2?4:2;
	leave[1]=0;
	rep(i,1,m)
	if(in[i])leave_add(i,-1);
}

void push(int x,int y,int d)
{
	if(g[x]>d){g[x]=d;fr[x]=y;q[++tail]=x;}
}
int bfs()
{	
	leave_init();
	 
	rep(i,1,m)
	if(in[i])
	{
		BING::init();
		rep(j,1,m)
		if(in[j]&&j!=i)BING::merge(e[j]);
		rep(j,1,m)
		if(!in[j])lk[i][j]=!BING::con(e[j]);
	}
	
	tail=0;
	BING::init();
	rep(i,1,m)
	if(in[i])BING::merge(e[i]);
	rep(i,1,m)
	{
		g[i]=m;
		if(!in[i]&&!BING::con(e[i]))push(i,0,0);
	}
	rep(head,1,tail)
	{
		int x=q[head];
		if(in[x])
		{
			rep(y,1,m)
			if(!in[y]&&lk[x][y])push(y,x,g[x]+1);
		}
		else
		{
			if(leave[e[x].first]&&leave[e[x].second])return x;
			rep(y,1,m)
			if(in[y])
			{
				leave_add(y,1);
				if(leave[e[x].first]&&leave[e[x].second])push(y,x,g[x]+1);
				leave_add(y,-1);
			}
		}
	}
	return 0;
}

void work()
{
	cin>>n1>>n2;
	m=0;
	rep(i,1,n1)scanf("%s",s[i]+1);
	
	auto check=[&](int x1,int y1,int x2,int y2)
	{
		if(s[x1][y1]=='O'&&s[x2][y2]=='O')
			e[++m]=pii((x1-1)*n2+y1,(x2-1)*n2+y2);
	};
	rep(i,1,n1)
	rep(j,1,n2-1)
		check(i,j,i,j+1);
	rep(i,1,n1-1)
	rep(j,1,n2)
		check(i,j,i+1,j);
		
	rep(i,1,m)in[i]=0;
	
	int x;
	while((x=bfs()))
	for(;x;x=fr[x])in[x]^=1;
	
	int Bcnt=0;
	rep(i,1,n1)
	rep(j,1,n2)
	if((i+j)%2==0&&s[i][j]=='O')++Bcnt;
	set<pii>S;BING::init();
	rep(i,1,m)
	if(in[i]){S.insert(e[i]);BING::merge(e[i]);}
	if(S.size()!=(Bcnt-1)*2)
	{
		puts("NO");
		return ;
	}
	rep(i,1,m)
	if(!BING::con(e[i])){S.insert(e[i]);BING::merge(e[i]);}
	puts("YES");
	rep(i,1,n1)
	{
		rep(j,1,n2)
		{
			printf("%c",s[i][j]);
			if(j<n2)putchar(S.count(pii((i-1)*n2+j,(i-1)*n2+j+1))?'O':' ');
		}
		puts("");
		if(i<n1)
		{
		rep(j,1,n2)
		{
			putchar(S.count(pii((i-1)*n2+j,i*n2+j))?'O':' ');
			if(j<n2)putchar(' ');
		}
		puts("");
		}
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)work();
}