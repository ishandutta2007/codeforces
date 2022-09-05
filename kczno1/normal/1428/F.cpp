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

const int N=5e5+5;
struct Node
{
	int mn,se_mn,mx,mn_cnt,len;
	s64 sum;
	bool upd(int w)
	{
		if(w<=mn)return 1;
		if(w>=mx)
		{
			mx=mn=w;se_mn=1e9;
			mn_cnt=len;
			sum=1LL*w*len;
			return 1;
		}
		if(w<se_mn)
		{
			sum+=1LL*(w-mn)*mn_cnt;
			mn=w;
		}
		return 0;
	}
};
Node node[N*4];

#define cl (k*2)
#define cr (k*2+1)
#define mid ((l+r)/2)
void push_up(int k)
{
	node[k].sum=node[cl].sum+node[cr].sum;
	node[k].mn=min(node[cl].mn,node[cr].mn);
	node[k].mn_cnt=(node[cl].mn==node[k].mn?node[cl].mn_cnt:0)+(node[cr].mn==node[k].mn?node[cr].mn_cnt:0);
	node[k].mx=max(node[cl].mx,node[cr].mx);
	node[k].se_mn=min(node[cl].mn==node[k].mn?node[cl].se_mn:node[cl].mn,node[cr].mn==node[k].mn?node[cr].se_mn:node[cr].mn);
}
void push_down(int k)
{
	node[cl].upd(node[k].mn);
	node[cr].upd(node[k].mn);
}
void init(int k,int l,int r)
{
	node[k].len=r-l+1;
	if(l==r)
	{
		node[k].se_mn=1e9;	
		node[k].mn_cnt=1;
		return ;
	}
	else 
	{
		init(cl,l,mid);
		init(cr,mid+1,r);
		push_up(k);
	}
}

int n,ql,qr,qw;
void dfs(int k,int l,int r)
{
	if(ql<=l&&qr>=r)
	{
		if(node[k].upd(qw))return ;
	}
	if(ql>r||qr<l)return ;
	push_down(k);
	dfs(cl,l,mid);
	dfs(cr,mid+1,r);
	push_up(k);
}
void upd(int l,int r,int w)
{
	ql=l;qr=r;qw=w;
	dfs(1,1,n);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n;
	init(1,1,n);

	static char s[N];
	scanf("%s",s+1);
	s64 ans=0;
	int last=1;
	rep(i,1,n)
	if(s[i]=='0')
	{
		rep(j,last,i-1)upd(j,j,i-j);
		ans+=node[1].sum;
		last=i+1;
	}
	else 
	{
		if(last>1)upd(1,last-1,i-last+1);
		ans+=node[1].sum+1LL*(i-last+1)*(i-last+2)/2;
	}
	cout<<ans<<endl;
}