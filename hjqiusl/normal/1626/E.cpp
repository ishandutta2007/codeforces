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
//#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int f1[N],f2[N],ans[N];
vector<int>g[N];
int c[N];
int siz[N];
int n;
void ad(int x,int y)
{
	g[x].push_back(y);
}
void dfs(int k,int fa)
{
	int x=c[k];
	siz[k]=c[k];
	for (auto u:g[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		siz[k]+=siz[u];
		x|=c[u];
		f1[k]|=f1[u];
	}
	f1[k]|=(x&&(siz[k]>=2));
	// for (auto u:g[k])
	// {
		// if (u==fa) continue;
		// dfs(u,k);
		// if (c[u]==1&&f3[k]) f2[k]=1;
		// if (f4[k]&&(f3[u]||c[u]==1)) f2[k]=1;
		// if (c[u]==1) f4[k]=1;
		// f3[k]|=(f3[u]||c[u]==1);
		// f1[k]|=f1[u];
		// f2[k]|=f2[u];
		// if (f3[k]&&c[k]) f1[k]=1;
	// }
	// cout<<k<<" "<<f1[k]<<" "<<f2[k]<<" "<<f3[k]<<" "<<f4[k]<<endl;
}
void dfs1(int k,int fa)
// ,int fa1,int fa2,int fa3,int fa4)
{
	int x=c[k],y=f2[k];
	for (auto u:g[k])
	{
		x+=c[u];
		if (u==fa) continue;
		y+=f1[u];
	}
	ans[k]=(x>0)|f1[k]|f2[k];
	for (auto u:g[k])
	{
		if (u==fa) continue;
		f2[u]=(y-f1[u]>0)||(x-c[u]>0&&siz[1]-siz[u]>=2);
		dfs1(u,k);
	}
	// if (k!=1)
	// {
		// int u=fa;
		// if (c[u]==1&&f3[k]) f2[k]=1;
		// if (f4[k]&&(fa3||c[u]==1)) f2[k]=1;
		// if (c[u]==1) f4[k]=1;
		// f3[k]|=(fa3||c[u]==1);
		// f1[k]|=fa1;
		// f2[k]|=fa2;
		// if (f3[k]&&c[k]) f1[k]=1;
	// }
	// int len=g[k].size();
	// vector<int>pre1(len),pre2(len),pre3(len),pre4(len),suf1(len),suf2(len),suf3(len),suf4(len);
	// for (int i=0;i<len;i++)
		// if (g[k][i]==fa)
		// {
			// swap(g[k][i],g[k][0]);
			// break;
		// }
	// for (int i=0;i<len;i++)
	// {
		// if (i>0)
		// {
			// pre1[i]=pre1[i-1];
			// pre2[i]=pre2[i-1];
			// pre3[i]=pre3[i-1];
			// pre4[i]=pre4[i-1];
		// }
		// int u=g[k][i];
		// if (c[u]==1&&pre3[i]) pre2[i]=1;
		// if (pre4[i]&&(f3[u]||c[u]==1)) pre2[i]=1;
		// if (c[u]==1) pre4[i]=1;
		// pre3[i]|=(f3[u]||c[u]==1);
		// pre1[i]|=f1[u];
		// pre2[i]|=f2[u];
		// if (pre3[i]&&c[k]) pre1[i]=1;
		// // cout<<"?????"<<k<<" "<<u<<" "<<i<<" "<<pre1[i]
	// }
	// for (int i=len-1;i>=0;i--)
	// {
		// if (i<len-1)
		// {
			// suf1[i]=suf1[i+1];
			// suf2[i]=suf2[i+1];
			// suf3[i]=suf3[i+1];
			// suf4[i]=suf4[i+1];
		// }
		// int u=g[k][i];
		// if (c[u]==1&&suf3[i]) suf2[i]=1;
		// if (suf4[i]&&(f3[u]||c[u]==1)) suf2[i]=1;
		// if (c[u]==1) suf4[i]=1;
		// suf3[i]|=(f3[u]||c[u]==1);
		// suf1[i]|=f1[u];
		// suf2[i]|=f2[u];
		// if (suf3[i]&&c[k]) suf1[i]=1;
	// }
	// if (k==1)
	// {
		// int now1=0,now2=0,now3=0,now4=0;
		// if (g[k].size()>1)
		// {
			// now1=suf1[1],now2=suf2[1],now3=suf3[1],now4=suf4[1];
		// }
		// dfs1(g[k][0],k,now1,now2,now3,now4);
	// }
	// for (int i=1;i<len;i++)
	// {
		// int now1=pre1[i-1],now2=pre2[i-1],now3=pre3[i-1],now4=pre4[i-1];
		// if (i<len-1)
		// {
			// if (now4&&suf3[i+1]) now2=1;
			// if (now3&&suf4[i+1]) now2=1;
			// now3|=suf3[i+1];
			// now1|=suf1[i+1];
			// now2|=suf2[i+1];
			// if (now3&&c[k]) now1=1;
		// }
		// dfs1(g[k][i],k,now1,now2,now3,now4);
	// }
}
			
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ad(x,y);
		ad(y,x);
	}
	dfs(1,0);
	dfs1(1,0);
	for (int i=1;i<=n;i++)
	{
		writesp(ans[i]);
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