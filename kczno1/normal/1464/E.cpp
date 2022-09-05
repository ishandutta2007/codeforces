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

const int D=998244353;
s64 mi(s64 x,int y=D-2)
{
	s64 ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%D;
		x=x*x%D;y>>=1;
	}
	return ans;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,edge_cnt;
	cin>>n>>edge_cnt;
	vector<vector<int>>lk(n),nlk(n);
	rep(i,1,edge_cnt)
	{
		int x=read()-1,y=read()-1;
		lk[x].push_back(y);
		nlk[y].push_back(x);
	}	

	vector<int>out_deg(n),sg(n);
	deque<int>q;
	rep(i,0,n-1)
	if(!(out_deg[i]=lk[i].size()))q.push_back(i);
	while(!q.empty())
	{
		int x=q.front();q.pop_front();
		
		int m=lk[x].size();
		vector<int>mark(m);
		for(auto y:lk[x])
		if(sg[y]<m)mark[sg[y]]=1;
		int i=0;
		while(i<m&&mark[i])++i;
		sg[x]=i;

		for(auto y:nlk[x])
		if(!(--out_deg[y]))q.push_back(y);
	}

	int m=*max_element(sg.begin(),sg.end());
	for(int i=1;i<=m;i<<=1)m|=i;
	++m;
	vector<int>cnt_of_sg(m);
	for(auto x:sg)++cnt_of_sg[x];
	vector<vector<s64>>a(m,vector<s64>(m+1));
	s64 niv_n_plus_1=mi(n+1);
	rep(i,0,m-1)
	{
		a[i][i]=1;
		rep(j,0,m-1)(a[i][j]-=cnt_of_sg[i^j]*niv_n_plus_1)%=D;
		if(i)a[i][m]=niv_n_plus_1;
	}
	rep(i,0,m-1)
	{
		s64 x=a[i][i];
		assert(x);
		s64 niv_x=mi(x);
		rep(j,i,m)(a[i][j]*=niv_x)%=D;
		rep(i1,i+1,m-1)
		{
			x=a[i1][i];
			if(!x)continue;
			rep(j,i,m)(a[i1][j]-=a[i][j]*x)%=D;
		}
	}
	rep(i,1,m-1)
	{
		s64 x=a[0][i];
		if(x)
		rep(j,i,m)(a[0][j]-=a[i][j]*x)%=D;
	}
	cout<<(a[0][m]+D)%D<<endl;
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/