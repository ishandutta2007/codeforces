//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define IOS ios::sync_with_stdio(false)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
vector<pa>G[N];
struct node
{
	int x,y,w;
}E[N];
int n;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int check(int x)
{
	set<int>S;
	for (int i=1;i<=x;i++) S.insert(E[i].x),S.insert(E[i].y);
	cout<<"? ";
	cout<<S.size()<<" ";
	for (auto u:S) cout<<u<<" ";
	cout<<endl;
	int res=0;
	cin>>res;
	return res;
}
void dfs(int k,int fa,int ds)
{
	for (auto U:G[k])
	{
		int u=U.fi,id=U.se;
		if (u==fa) continue;
		E[id].w=ds+1;
		dfs(u,k,ds+1);
	}
}
signed main()
{
	cin>>n;
	for (int i=1;i<n;i++)
	{
		cin>>E[i].x>>E[i].y;
		G[E[i].x].push_back({E[i].y,i});
		G[E[i].y].push_back({E[i].x,i});
		
	}
	dfs(1,0,0);
	sort(E+1,E+n,cmp);
	int l=1,r=n-1,now=check(n-1),ans=0;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (check(mid)==now)
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<"! "<<E[ans].x<<" "<<E[ans].y<<endl;
		
}
/*

*/