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

const int N=1e5+5;
vector<int>lk[N];
int n,fa[N],sz[N],w_to_fa[N];

void init_dfs(int x,int fr)
{
	fa[x]=fr;
	sz[x]=1;
	for(auto y:lk[x])
	if(y!=fr)
	{
		init_dfs(y,x);
		sz[x]+=sz[y];
	}
	w_to_fa[x]=min(sz[x],n-sz[x]);
}
vector<int>q[N];
int dy_q[N];
void work_dfs(int x)
{
	priority_queue<pii>heap;
	int sum=1;
	dy_q[x]=x;q[x].push_back(x);
	heap.push(pii(1,x));
	for(auto y:lk[x])
	if(y!=fa[x])
	{
		work_dfs(y);
		heap.push(pii(q[dy_q[y]].size(),y));
		sum+=q[dy_q[y]].size();
	}
	while(sum>w_to_fa[x])
	{
		sum-=2;
		int x1=heap.top().second;heap.pop();
		int x2=heap.top().second;heap.pop();
		printf("%d %d\n",q[dy_q[x1]].back(),q[dy_q[x2]].back());
		q[dy_q[x1]].pop_back();
		q[dy_q[x2]].pop_back();
		heap.push(pii(q[dy_q[x1]].size(),x1));
		heap.push(pii(q[dy_q[x2]].size(),x2));
	}	
	int son=heap.top().second;
	dy_q[x]=dy_q[son];
	if(dy_q[x]!=x)q[dy_q[x]].insert(q[dy_q[x]].end(),q[x].begin(),q[x].end());
	for(auto y:lk[x])
	if(y!=fa[x]&&y!=son)
		q[dy_q[x]].insert(q[dy_q[x]].end(),q[dy_q[y]].begin(),q[dy_q[y]].end());
}

s64 check(int mid)
{
	s64 ans=0;
	rep(i,2,n)
	{
		ans+=w_to_fa[i];
		if(w_to_fa[i]>=mid)ans-=2*((w_to_fa[i]-mid)/2+1);
	}
	return ans;
}
s64 k;
int binarySearch_work()
{
	s64 sum=check(n);
	//cerr<<sum<<endl;
	if(k>sum||(sum-k)%2){puts("NO");exit(0);}
	if(check(2)>k){puts("NO");exit(0);}
	int l=0,r=n;
	while(l+1!=r)
	{
		int mid=(l+r)/2;
		if(check(mid)>=k)r=mid;
		else l=mid;
	}
	return r;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n>>k;
	rep(i,2,n)
	{
		int x=read(),y=read();
		lk[x].push_back(y);
		lk[y].push_back(x);
	}
	init_dfs(1,0);

	int mid=binarySearch_work();
	int del=check(mid)-k;
	rep(i,2,n)
	{
		if(w_to_fa[i]>=mid)w_to_fa[i]-=((w_to_fa[i]-mid)/2+1)*2;
		if(del&&w_to_fa[i]==mid-1){del-=2;w_to_fa[i]-=2;}
	}

	puts("YES");
	work_dfs(1);
}