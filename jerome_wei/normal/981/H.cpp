#include<bits/stdc++.h>
#define ll long long
#define FIO "game"
using namespace std;

const int N=1e5+5,MOD=998244353,P=18;

int fac[N],inv[N],invc[N],w[2][1<<P],rev[1<<P];

inline int add(int a,const int &b){if((a+=b)>=MOD)a-=MOD;return a;}
inline int sub(int a,const int &b){if((a-=b)<		0)a+=MOD;return a;}
inline int mul(const int &a,const int &b){return 1ll*a*b%MOD;}
inline void inc(int &a,const int &b){a=add(a,b);}
inline void dec(int &a,const int &b){a=sub(a,b);}
inline void pro(int &a,const int &b){a=mul(a,b);}
inline int qpow(int a,int b){int c=1;for(;b;b>>=1,pro(a,a))if(b&1)pro(c,a);return c;}
inline int p(const int &a,const int &b){return a>=b?mul(fac[a],invc[a-b]):0;}

inline void pre(){
	fac[0]=fac[1]=inv[0]=inv[1]=invc[0]=invc[1]=1;
	for(int i=2;i<N;i++)fac[i]=mul(fac[i-1],i),inv[i]=mul(inv[MOD%i],MOD-MOD/i),invc[i]=mul(invc[i-1],inv[i]);
	for(int i=1;i<1<<P;i<<=1){
		w[0][i]=w[1][i]=1;
		int wn1=qpow(3,(MOD-1)/(i<<1)),wn0=qpow(wn1,MOD-2);
		for(int j=1;j<i;j++)
			w[0][i+j]=mul(w[0][i+j-1],wn0),w[1][i+j]=mul(w[1][i+j-1],wn1);
	}
}

inline void ntt(int *f,int opt,int l){
	for(int i=0;i<l;i++){rev[i]=rev[i>>1]>>1|(i&1)*l>>1;if(i<rev[i])swap(f[i],f[rev[i]]);}
	for(int i=1;i<l;i<<=1)
		for(int j=0;j<l;j+=i<<1)
			for(int k=0;k<i;k++){
				int x=f[j+k],y=mul(f[i+j+k],w[opt][i+k]);
				f[j+k]=add(x,y);
				f[i+j+k]=sub(x,y);
			}
	if(opt)for(int i=0,inv=qpow(l,MOD-2);i<l;i++)pro(f[i],inv);
}

#define poly vector<int>

inline void out(const poly &a){
	for(int i=0,n=a.size();i<n;i++)printf("%d%c",a[i],i^n-1?' ':'\n');
}

inline void clear(poly &a){
	int n=a.size();
	while(n>1&&!a[n-1])n--;
	a.resize(n);
}

int n,k,ans,sz[N],dp[N],sum[N];
inline poly operator *(poly a,poly b){
	int n=a.size(),m=b.size(),l=1;
	while(l<n+m)l<<=1;
	a.resize(l);b.resize(l);
	ntt(&a[0],0,l);ntt(&b[0],0,l);
	for(int i=0;i<l;i++)pro(a[i],b[i]);
	ntt(&a[0],1,l);
	a.resize(min(k+1,n+m-1));
	clear(a);
	return a;
}

inline poly& operator *=(poly &a,const poly &b){return a=a*b;}

inline poly operator /(poly a,const int &b){
	for(int i=0,n=a.size();i<n-1;i++)if(a[i])dec(a[i+1],mul(a[i],b));
	clear(a);
	return a;
}

int h[N],to[N<<1],nxt[N<<1],ecnt;
inline void adde(int u,int v){nxt[++ecnt]=h[u];h[u]=ecnt;to[ecnt]=v;}

inline poly solve(const vector<poly> &a,int l=0,int r=-1){
	if(r==-1)r=a.size()-1;
	if(l==r)return a[l];
	int mid=(l+r)>>1;
	return solve(a,l,mid)*solve(a,mid+1,r);
}

inline int calc(const poly &a){
	int ret=0;
	for(int i=0,n=a.size();i<min(k,n);i++)inc(ret,mul(a[i],p(k,i)));
	return ret;
}

inline bool cmp(const int &a,const int &b){return sz[a]<sz[b];}

inline void dfs1(int u=1,int fa=0){
	vector<poly>a;
	poly b;
	sz[u]=1;
	poly tmp(2,1);
	for(int i=h[u],v;i;i=nxt[i])if((v=to[i])^fa){
		dfs1(v,u);
		tmp[1]=sz[v];
		a.push_back(tmp);
		b.push_back(v);
		sz[u]+=sz[v];
		inc(sum[u],sum[v]);
	}
	if(a.empty()){dp[u]=sum[u]=1;return;}
	poly f=solve(a);inc(sum[u],dp[u]=calc(f));
int m=f.size(); f.resize(m+1); for(int i=m;i;i--)inc(f[i],mul(f[i-1],n-sz[u]));
	//tmp[1]=n-sz[u];f*=tmp;
	sort(b.begin(),b.end(),cmp);
	for(int i=0,lst=0,n=b.size();i<n;i++){
		if(i&&sz[b[i]]==sz[b[i-1]])inc(ans,mul(sum[b[i]],lst));
		else inc(ans,mul(sum[b[i]],lst=calc(f/sz[b[i]])));
	}
}

inline void dfs2(int u=1,int fa=0){
	for(int i=h[u],v,s=0;i;i=nxt[i])if((v=to[i])^fa){
		dfs2(v,u);
		inc(ans,mul(s,sum[v]));
		inc(s,sum[v]);
	}
}

int main(){
	pre();
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs1();
//	printf("ans=%d\n",ans);
	dfs2();
	printf("%d\n",ans);
	return 0;
}