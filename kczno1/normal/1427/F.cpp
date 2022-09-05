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

const int N=1200+5;
bool col[N];
int match[N];
int fa[N],du[N];bool ex[N];
int st[N],top;

vector<int>a[3];
void push(int l)
{
	if(col[l])a[2].push_back(l);
	else a[ex[l]].push_back(l);
}
void print(int x)
{
	printf("%d %d %d\n",x,match[x],match[match[x]]);
	if(!--du[fa[x]])push(fa[x]);
}
void build(int l,int r,int fr)
{
	if(l>r)return ;
	ex[l]=ex[fr]|col[l];
	fa[l]=fr;++du[fr];
	int l1=match[l],l2=match[l1];
	build(l+1,l1-1,l);
	build(l1+1,l2-1,l);
	build(l2+1,r,fr);
	if(!du[l])push(l);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n;
	rep(tmp,1,3*n)col[read()]=1;
	rep(i,1,6*n)
	{
		st[++top]=i;
		if(top>=3&&col[st[top-2]]==col[st[top]]&&col[st[top-1]]==col[st[top]])
		{
			rep(i,top-2,top-1)match[st[i]]=st[i+1];
			top-=3;
		}
	}	
	build(1,6*n,0);	
	rep(tmp,1,n)
	{
		assert(!a[2].empty());
		int x=a[2].back();
		a[2].pop_back();
		print(x);
		per(i,1,0)
		if(!a[i].empty())
		{
			int x=a[i].back();
			a[i].pop_back();
			print(x);
			break;
		}
	}
}