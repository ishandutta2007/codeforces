#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 1<<18|3, mo = 998244353;
int n,sz[N],son[N],Fa[N];ll x;vector<int> e[N];
void dfs1(int u, int fa){
	Fa[u]=fa;sz[u]=1;rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa){
		dfs1(e[u][i],u),sz[u]+=sz[e[u][i]];if(sz[e[u][i]]>sz[son[u]])son[u]=e[u][i];
	}
}
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline int power(int a, int n){
	int res=1;
	while(n){
		if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;
	}	
	return res;
}
int len,w[N];vector<int> h[N],t[N];
inline vector<int> add(vector<int> a, vector<int> b){
	if(SZ(a)>=SZ(b)){rep(i,0,SZ(b)-1)add(a[i],b[i]);return a;}
	rep(i,0,SZ(a)-1)add(b[i],a[i]);return b;
}
inline void fft(int *a, int n, int tp){
	for(int i=1,j=0;i<n;i++){
		for(int k=n>>1;!((j^=k)&k);k>>=1);if(i<j)swap(a[i],a[j]);
	}
	for(int j=2;j<=n;j<<=1){
		w[0]=1;w[1]=power(3,(mo-1)/j);if(tp==-1)w[1]=power(w[1],mo-2);
		rep(i,2,(j>>1)-1)w[i]=1LL*w[i-1]*w[1]%mo;
		for(int k=0;k<n;k+=j)rep(i,0,(j>>1)-1){
			int x=a[k+i],y=1LL*w[i]*a[k+i+(j>>1)]%mo;
			a[k+i]=x+y<mo?x+y:x+y-mo;a[k+i+(j>>1)]=x-y>=0?x-y:x-y+mo;
		}
	}
}
inline vector<int> mul(vector<int> a, vector<int> b){
	if(1LL*SZ(a)*SZ(b)<=5000){
		vector<int> c;c.resize(SZ(a)+SZ(b)-1);
		rep(i,0,SZ(a)-1)rep(j,0,SZ(b)-1)c[i+j]=(c[i+j]+1LL*a[i]*b[j])%mo;
		return c;
	}
	int n;for(n=1;n<=SZ(a)+SZ(b)-1;n<<=1);static int f[N],g[N];
	rep(i,0,SZ(a)-1)f[i]=a[i];rep(i,SZ(a),n-1)f[i]=0;
	rep(i,0,SZ(b)-1)g[i]=b[i];rep(i,SZ(b),n-1)g[i]=0;
	fft(f,n,1);fft(g,n,1);rep(i,0,n-1)f[i]=1LL*f[i]*g[i]%mo;fft(f,n,-1);
	int ni=power(n,mo-2);vector<int> c;rep(i,0,SZ(a)+SZ(b)-1)c.pb(1LL*ni*f[i]%mo);return c;
}
inline void solve(int l, int r, vector<int> &f, vector<int> &g){
	if(l==r){f=g=h[l];return;}int mid=(l+r)>>1;
	vector<int> fl,fr,gl,gr;solve(l,mid,fl,gl);solve(mid+1,r,fr,gr);
	f=mul(fl,fr);g=add(mul(gr,fl),gl);
}
inline vector<int> dfs2(int u, int fa){
	for(int x=u;x;x=son[x]){
		t[x].clear();
		rep(i,0,SZ(e[x])-1)
			if(e[x][i]!=son[x]&&e[x][i]!=Fa[x]) t[x]=dfs2(e[x][i],x);
		if(SZ(t[x])<1)t[x].resize(1);
		t[x][0]++;
		t[x].insert(t[x].begin(),0);
	}
	len=0;
	for(int x=u;x;x=son[x]) h[++len]=t[x];
	vector<int> f,g;
	solve(1,len,f,g);
	return g;
}
int main() {
	n=read();scanf("%lld",&x);x%=mo;
	rep(i,1,n-1){
		int u,v;
		u=read();v=read();
		e[u].pb(v);e[v].pb(u);
	}
	dfs1(1,0);
	vector<int> res=dfs2(1,0);
	ll ans=0,now=1;
	rep(i,1,SZ(res)-1){
		ans=(ans+now*res[i])%mo;now=now*(x+i)%mo*power(i,mo-2)%mo;
	}
	cout<<ans;
	return 0;
}