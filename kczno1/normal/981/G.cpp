#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2e5+5,T=N*4,D=998244353;
int n;
map<int,int>mp[N];
#define cl (k*2)
#define cr (cl+1)
#define mid ((l+r)/2)
#define in (ql<=l&&qr>=r)
#define out (ql>r||qr<l)
#define left cl,l,mid
#define right cr,mid+1,r
namespace SEG
{
struct Tag
{
	s64 a,b;
};
Tag operator +(const Tag &x,const Tag &y)
{
	return {x.a*y.a%D,(x.b*y.a+y.b)%D};
}
Tag tag[T],now;
s64 s[T];
int ql,qr;
void add(int k,int l,int r,const Tag &x)
{
	s[k]=(s[k]*x.a+(r-l+1)*x.b)%D;
	tag[k]=tag[k]+x;
}
void up(int k)
{
	s[k]=(s[cl]+s[cr])%D;
}
void down(int k,int l,int r)
{
	add(left,tag[k]);
	add(right,tag[k]);
	tag[k]={1,0};
}
void add_dfs(int k,int l,int r)
{
	if(in)
	{
		add(k,l,r,now);
		return ;
	}
	if(out)return ;
	down(k,l,r);
	add_dfs(left);add_dfs(right);
	up(k);
}
void add(int l,int r,Tag x)
{
	ql=l;qr=r;now=x;
	add_dfs(1,1,n);
}
s64 ans;
void query_dfs(int k,int l,int r)
{
	if(in)
	{
		ans+=s[k];
		return ;
	}
	if(out)return ;
	down(k,l,r);
	query_dfs(cl,l,mid);
	query_dfs(cr,mid+1,r);
}
int query(int l,int r)
{
	ans=0;
	ql=l;qr=r;
	query_dfs(1,1,n);
	return (ans%D+D)%D;
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	int m;
	cin>>n>>m;
	while(m--)
	{
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if(t==1)
		{
			int x;
			scanf("%d",&x);
			auto it=mp[x].lower_bound(l+1);
			int nr=l-1;
			if(it!=mp[x].begin())
			{
				--it;
				if(it->second>=nr)
				{
					if(it->second>=r)
					{
						SEG::add(l,r,{2,0});
						continue;
					}
					SEG::add(l,nr=it->second,{2,0}); 
					l=it->first;
				}
			}
			while(1)
			{
				auto it=mp[x].lower_bound(nr+1);
				if(it==mp[x].end()||it->first>r)
				{
					SEG::add(nr+1,r,{1,1});
					break;
				}
				SEG::add(nr+1,it->first-1,{1,1});
				if(it->second>=r)
				{
					SEG::add(it->first,r,{2,0});
					r=it->second;
					mp[x].erase(it);
					break;
				}
				SEG::add(it->first,it->second,{2,0});
				nr=it->second;
				mp[x].erase(it);
			}
			mp[x][l]=r;
		}
		else printf("%d\n",SEG::query(l,r));
	}
}