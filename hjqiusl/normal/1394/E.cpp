//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n;
vector<int>L[N],R[N];
map<int,int>F[N];
int a[N];
int m;
int ans;
void del(int x,int y)
{
	for (int i=y;i>=x;i--)
	{
		for (auto u:L[i])
		{
			R[u].pop_back();
		}
		L[i].clear();
		R[i].clear();
		F[i].clear();
	}
}
int work(int l,int r)
{
	if (l>r) return 0;
	if (F[r].count(l))
	{
		// cout<<"!?"<<l<<" "<<r<<" "<<F[r][l]<<endl;
		return F[r][l];
	}
	int res=0;
	for (auto u:R[l])
	{
		if (u<=r)
			res=max(res,work((l+u)/2+1,r)+1);
	}
	for (auto u:L[r])
	{
		if (u>=l)
			res=max(res,work(l,(r+u)/2)+1);
	}
	F[r][l]=res;
	// cout<<"!!"<<l<<" "<<r<<" "<<res<<endl;
	return res;
}
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		a[m+1]=x;
		if (a[m]==x)
		{
			// cout<<"?"<<x<<" "<<x<<" "<<m<<" "<<m+1<<" "<<i<<endl;
			L[m+1].push_back(m),R[m].push_back(m+1);
		}
		for (auto u:L[m])
		{
			if (u!=1&&a[u-1]==x)
			{
				L[m+1].push_back(u-1),R[u-1].push_back(m+1);
				// cout<<"?"<<a[u-1]<<" "<<x<<" "<<u-1<<" "<<m+1<<" "<<i<<endl;
			}
		}
		++m;
		for (auto u:L[m])
		{
			int len=(m-u+1)/2;
			int x=u-len;
			if (x<=0) continue;
			int y=lower_bound(R[x].begin(),R[x].end(),u+len-1)-R[x].begin();
			if (y==R[x].size()||R[x][y]!=u+len-1) continue;
			del(u,m);
			m=u-1;
			ans+=2;
			break;
		}
		// for (int j=1;j<=m;j++) cout<<a[j]<<" ";
		// cout<<endl;
		writesp(work(1,m)+ans);
		// cout<<"?"<<ans<<endl;
	}
		
		
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/