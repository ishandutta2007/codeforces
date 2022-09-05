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

int ans;
map<pii,int>Map;
int query(int i,int j)
{
	if(Map.count({i,j}))
	{
#ifdef kcz
	chmin(ans,Map[{i,j}]);
#endif
		return Map[{i,j}];
	}
	printf("? %d %d\n",i,j);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	chmin(ans,x);
	return Map[{i,j}]=x;
}	
const int N=1e6+5;
int mn_col[N],st[N],top,dy[N];
void work(vector<int> row,vector<int> col)
{
	int n=row.size(),m=col.size();
	if(n<=1)
	{
		for(auto i:row)
		{
			int mn_x=1e9+5;
			for(auto j:col)
			{
				int x=query(i,j);
				if(x<mn_x){mn_x=x;mn_col[i]=j;}
			}
		}
		return ;
	}
	if(m>n*3)
	{
		top=0;
		for(auto j:col)
		{
			while(top)
			{
				int x=query(row[top-1],st[top]),y=query(row[top-1],j);
				if(x<y)break;
				else --top;
			}
			if(top<n)st[++top]=j;
		}
		m=top;
		col.resize(m);
		rep(i,0,m-1)col[i]=st[i+1];
	}
	vector<int>row1(n/2);
	for(int i=1;i<n;i+=2)row1[i/2]=row[i];
	work(row1,col);
	rep(i,0,m-1)dy[col[i]]=i;
	for(int i=0;i<n;i+=2)
	{
		int l=0,r=m-1;
		if(i)l=dy[mn_col[row[i-1]]];
		if(i+1<n)r=dy[mn_col[row[i+1]]];
		int mn_x=1e9+5;
		rep(j,l,r)			
		{
			int x=query(row[i],col[j]);
			if(x<mn_x){mn_x=x;mn_col[row[i]]=col[j];}
		}
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
#ifdef kcz
	rep(i,1,n)
	rep(j,1,m)Map[{i,j}]=read();
#endif
	vector<int>row(n),col(m);
	rep(i,0,n-1)row[i]=i+1;
	rep(i,0,m-1)col[i]=i+1;
	ans=1e9;
	work(row,col);
	printf("! %d\n",ans);
}