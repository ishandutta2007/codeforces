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

const int N=1e5+5;
vector<int>lk[N];
bool mark[N];
int deg[N];
void work()
{
	int n=read(),m=read(),k=read();
	rep(i,1,n)
	{
		lk[i].clear();mark[i]=deg[i]=0;
	}
	rep(i,1,m)
	{
		int x=read(),y=read();
		lk[x].push_back(y);
		lk[y].push_back(x);
		++deg[x];++deg[y];
	}
	if(s64(k)*(k-1)/2>m)
	{
		puts("-1");
		return ;
	}
	rep(i,1,n)sort(lk[i].begin(),lk[i].end());
	deque<int>q;
	rep(i,1,n)
	if(deg[i]<=k-1)
		q.push_back(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop_front();
		mark[x]=1;
		vector<int>nq;
		nq.push_back(x);
		for(auto y:lk[x])
		if(!mark[y])
		{
			nq.push_back(y);
			if(--deg[y]==k-1)
				q.push_back(y);
		}
		if(nq.size()==k)
		{
			rep(i,1,k-1)
			{
				int x=nq[i];
				rep(j,i+1,k-1)
				{
					int y=nq[j];
					auto it=lower_bound(lk[x].begin(),lk[x].end(),y);
					if(it==lk[x].end() || *it!=y)goto End;
				}
			}
			printf("%d\n",2);
			rep(i,0,k-1)printf("%d%c",nq[i]," \n"[i==k-1]);
			return ;
			End:;
		}
	}
	rep(i,1,n)
	if(!mark[i])q.push_back(i);
	if(q.empty())puts("-1");
	else 
	{
		printf("1 %d\n",int(q.size()));
		for(auto x:q)printf("%d ",x);
		puts("");
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
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/