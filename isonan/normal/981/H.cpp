#include <bits/stdc++.h>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int n,K;
int head[100001],nxt[200001],b[200001],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int _mul[100001],invmul[100001],size[100001];
int sum,ans,lim;
int t1[1000001],t2[1000001],t3[1000001],t4[1000001],w[1000001],R[1000001];
int C(int n,int m){if(n<m||m<0)return 0;return mul(mul(_mul[n],invmul[m]),invmul[n-m]);}
void NTT(int *a){
	for(int i=0;i<lim;i++)if(i<R[i])std::swap(a[i],a[R[i]]);
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++){
				const int Ny=mul(a[i+j+k],w[i+k]);
				a[i+j+k]=sub(a[j+k],Ny);
				a[j+k]=add(a[j+k],Ny);
			}
}
typedef std::vector<int> poly;
void dfs(int x,int f){
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
			size[x]+=size[b[i]];
		}
}
poly f[100001],h[100001];
int g[100001];
void solve(int l,int r){
	if(l>=r)return;
//	int bl=(r-l+1)/std::max(2,(int)(log(r-l+1)/log(2)));
	int bl=(r-l+2)>>1;
	for(int i=l;i<=r;i+=bl)
		solve(i,std::min(i+bl-1,r));
	lim=1;
	while(lim<(r-l+2))lim<<=1;
	for(int i=0;i<lim;i++)R[i]=(R[i>>1]>>1)|((i&1)?lim>>1:0);
	for(int i=0;i<lim;i++)t1[i]=1,t2[i]=0;
//	printf("solve %d %d\n",l,r);
	int inv=qsm(lim,P-2);
	for(int i=l;i<=r;i+=bl){
		memset(t3,0,lim<<2);
		memset(t4,0,lim<<2);
		for(int j=0;j<f[i].size();j++)t3[j]=f[i][j];
		for(int j=0;j<h[i].size();j++)t4[j]=h[i][j];
//		for(int j=0;j<f[i].size();j++)printf("%d ",f[i][j]);putchar('\n');
//		for(int j=0;j<h[i].size();j++)printf("%d ",h[i][j]);putchar('\n');
		NTT(t3);
		NTT(t4);
		for(int i=0;i<lim;i++){
			t2[i]=add(mul(t1[i],t4[i]),mul(t2[i],t3[i]));
			t1[i]=mul(t1[i],t3[i]);
		}
	}
	NTT(t1);
	NTT(t2);
	std::reverse(t1+1,t1+lim);
	std::reverse(t2+1,t2+lim);
	f[l].resize(r-l+2);
	for(int i=0;i<=r-l+1;i++)f[l][i]=mul(t1[i],inv);
	h[l].resize(r-l+2);
	for(int i=0;i<=r-l+1;i++)h[l][i]=mul(t2[i],inv);
//		for(int j=0;j<f[l].size();j++)printf("%d ",f[l][j]);putchar('\n');
//		for(int j=0;j<h[l].size();j++)printf("%d ",h[l][j]);putchar('\n');
}
void getans(int x,int F){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			getans(b[i],x);
			g[x]=add(g[x],g[b[i]]);
		}
	int top=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			++top;
			f[top].clear();
			f[top].push_back(1);
			f[top].push_back(size[b[i]]);
			h[top].clear();
			h[top].push_back(g[b[i]]);
			h[top].push_back(mul(n-size[x],g[b[i]]));
		}
	solve(1,top);
	int v=0;
	if(top){
//		printf("get %d\n",x);
//		for(int i=head[x];i;i=nxt[i])
//			if(b[i]!=F)printf("%d ",size[b[i]]);putchar('\n');
//		for(int i=0;i<f[1].size();i++)printf("%d ",f[1][i]);putchar('\n');
//		for(int i=0;i<h[1].size();i++)printf("%d ",h[1][i]);putchar('\n');
		for(int i=0;i<f[1].size()&&i<=K;i++)v=add(v,mul(f[1][i],mul(_mul[K],invmul[K-i])));
		for(int i=0;i<h[1].size()&&i<=K;i++)ans=add(ans,mul(h[1][i],mul(_mul[K],invmul[K-i])));
	}
	else v=1;
//	printf("%d %d\n",sub(sum,g[x]),v);
	ans=add(ans,mul(sub(sum,g[x]),v));
	g[x]=add(g[x],v);
	sum=add(sum,v);
}
int main(){
	scanf("%d%d",&n,&K);
	if(K==1){
		printf("%d",mul(mul(n,n-1),(P+1)>>1));
		return 0;
	}
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=K;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=K;i++)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=K;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
	for(int i=1,wn;i<((n+1)<<3);i<<=1){
		wn=qsm(3,(P-1)/(i<<1));
		w[i]=1;
		for(int j=1;j<i;j++)w[i+j]=mul(w[i+j-1],wn);
	}
	dfs(1,0);
	getans(1,0);
	printf("%d\n",ans);
}