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

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n,m;
		cin>>n>>m;
		vector<string> a(n);
		rep(i,0,n-1)cin>>a[i];
		set<vector<pii>> ans;
		auto push=[&](vector<pii> q)
		{
			sort(q.begin(),q.end());
			if(ans.count(q))ans.erase(q);
			else ans.insert(q);
			for(auto p:q)a[p.first][p.second]^=1;
		};
		rep(i,0,n-2)
		for(int j=0;j<m;j+=2)
		{
			if(j==m-1)--j;
			vector<pii> q;
			rep(k,j,j+1)
			if(a[i][k]=='1')q.push_back({i,k});
			rep(k,j,j+1)
			if(q.size()<3)q.push_back({i+1,k});
			if(q.size()==3)push(q);
		}
		rep(j,0,m-2)
		{
			vector<pii> q;
			rep(i,n-2,n-1)
			if(a[i][j]=='1')q.push_back({i,j});
			rep(i,n-2,n-1)
			if(q.size()<3)q.push_back({i,j+1});
			if(q.size()==3)push(q);
		}		
		if(a[n-2][m-1]=='1' && a[n-1][m-1]=='1')
		{
			push({{n-2,m-2},{n-2,m-1},{n-1,m-2}});			
			push({{n-2,m-2},{n-1,m-2},{n-1,m-1}});			
		}
		else 
		if(a[n-2][m-1]=='1' || a[n-1][m-1]=='1')
		{
			vector<pii> q1={{n-2,m-2},{n-2,m-1},{n-1,m-2},{n-1,m-1}};
			rep(i,0,3)
			{
				vector<pii> q;
				rep(j,0,3)
				if(j!=i)q.push_back(q1[j]);
				push(q);
			}
			if(a[n-2][m-1]=='1')
				push({{n-2,m-2},{n-2,m-1},{n-1,m-2}});			
			else 
				push({{n-2,m-2},{n-1,m-2},{n-1,m-1}});			
		}
		bool ok=1;
		rep(i,0,n-1)
		rep(j,0,m-1)ok&=(a[i][j]=='0');
		if(!ok)
		{
			rep(i,0,n-1)cout<<a[i]<<endl;
			exit(0);
		}
		printf("%d\n",int(ans.size()));
		for(auto q:ans)
		rep(i,0,2)printf("%d %d%c",q[i].first+1,q[i].second+1," \n"[i==2]);
	}	
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/