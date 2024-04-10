#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
int mul(int a,int b){return (ll)a*b%mod;}
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
const int N = 3e5+5;
int f[N][2],n;
int g[N];
int hed[N],to[N<<1],nxt[N<<1],cnt;
inline void adde(int u,int v){
	++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
}

inline void dfs(int x,int pre){
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		dfs(v,x);
	}
	g[x]=1, f[x][0]=f[x][1]=1;//f:
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		int s0=add(mul(f[v][0],2),mul(f[v][1],2));
		s0=add(s0,mul(g[v],2+1));
		int s1=add(mul(f[v][0],2),mul(f[v][1],1));
		s1=add(s1,mul(g[v],1+1));
		int s3=add(f[v][0],add(f[v][1],g[v]));
		// cout << x << " " << v << ":" << s0 << " " << s1 << " " << s3 << endl;
		f[x][0]=mul(f[x][0],s0);
		f[x][1]=mul(f[x][1],s1);
		g[x]=mul(g[x],s3);
	}
	f[x][0]=sub(f[x][0],g[x]);
	f[x][1]=sub(f[x][1],g[x]);
	// cout << x << " : " << f[x][0] << " " << f[x][1] << " " << g[x] << endl;
}

int main()
{
	cin >> n;
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v),adde(v,u);
	}
	dfs(1,0);
	// cout << f[1][0] << " " << f[1][1] << " " << g[1] << endl;
	cout << sub(add(add(f[1][1],f[1][0]),g[1]),1) << endl;
}