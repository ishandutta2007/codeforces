//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 3000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,chs[N],vis[N],col[N];
vector<int>G[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int c)
{
	if (vis[k]) return;
	vis[k]=1;
	col[k]=c;
	for (auto u:G[k])
	{
		if (vis[u]) continue;
		dfs(u,c^1);
	}
}
void LYC_music()
{
	cin>>n;
	if (n%2==0)
	{
		cout<<"First"<<endl;
		for (int i=1;i<=n*2;i++)
			cout<<(i-1)%n+1<<" ";
		cout<<endl;
	} else
	{
		cout<<"Second"<<endl;
		int x;
		for (int i=1;i<=2*n;i++)
		{
			cin>>x;			
			if (chs[x])
			{
				ad(chs[x],i);
				ad(i,chs[x]);
			} else
				chs[x]=i;
		}
		for (int i=1;i<=n;i++)
			ad(i,i+n),ad(i+n,i);
		for (int i=1;i<=n;i++)
			if (!vis[i]) dfs(i,1);
			int sum=0;
		for (int i=1;i<=n*2;i++)
			if (col[i]) sum+=i;
		if (sum%(2*n)==0) 
		{
			for (int i=1;i<=n*2;i++) 
				if (col[i]) cout<<i<<" ";
		} else
			for (int i=1;i<=n*2;i++)
				if (!col[i]) cout<<i<<" ";
		cout<<endl;
	}
	int x;
	cin>>x;
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/