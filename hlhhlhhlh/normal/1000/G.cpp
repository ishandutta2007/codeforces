#include<bits/stdc++.h>
using namespace std;
const int maxn=300010;
int i,j,k;
int n,q,x,y,z,xx,yy;
int f1[maxn],f2[maxn*2],f4[maxn*2],th;
int a[maxn];
long long dp[maxn],f[maxn*2],f3[maxn*2],ans[maxn];
int g[21][maxn],gg[maxn],dept[maxn];
long long tot[maxn],anss;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-')fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void add(int x,int y,int z){
	th++; f2[th]=y; f3[th]=z; f4[th]=f1[x]; f1[x]=th;
}
void dfs(int x,int fa){
	int i=f1[x],j;
	dept[x]=dept[fa]+1;
	g[0][x]=fa;
	for (j=1;j<=20;j++) g[j][x]=g[j-1][g[j-1][x]];
	dp[x]=a[x];
	while (i!=0){
		if (f2[i]!=fa){
			dfs(f2[i],x); f[i]=dp[f2[i]];
			if (i%2==1) gg[f2[i]]=i+1; else gg[f2[i]]=i-1;
			if (dp[x]<dp[x]-f3[i]*2+dp[f2[i]]) tot[f2[i]]=tot[f2[i]]+f3[i];
			else tot[f2[i]]=-f3[i]+dp[f2[i]];
			dp[x]=max(dp[x],dp[x]-f3[i]*2+dp[f2[i]]);
		}
		i=f4[i];
	}
}
long long dfs2(int x,int fa){
	int t;
	if (fa==0){
		return max(dp[x],dp[x]+dfs2(g[0][x],gg[x])-2*f3[gg[x]]);
	}
	if (f[fa]!=0) return f[fa];
	else{
		if (fa%2==1) t=f2[fa+1]; else t=f2[fa-1];
		if (dp[t]-2*f3[fa]>0) f[fa]=dp[x]-(dp[t]-2*f3[fa]); else f[fa]=dp[x];
		if (g[0][x]!=0){
			f[fa]=max(f[fa],f[fa]+dfs2(g[0][x],gg[x])-2*f3[gg[x]]);
		}
		return f[fa];
	}
}
void dfs1(int x,int fa){
	int i=f1[x];
	tot[x]=tot[x]+tot[fa];
	while (i!=0){
		if (f2[i]!=fa){
			dfs1(f2[i],x);
		}
		i=f4[i];
	}
}
int lca(int x,int y){
	int i;
	if (dept[x]<dept[y]) swap(x,y);
	for (i=20;i>=0;i--){
		if (dept[g[i][x]]>=dept[y]){ x=g[i][x]; }
	}
	if (x==y) return x;
	for (i=20;i>=0;i--){
		if (g[i][x]!=g[i][y]){
			x=g[i][x]; y=g[i][y]; 
		}
	}
	return g[0][x];
}
int getkth(int x,int k){
	int i=1,j=0;
	while (k!=0){
		if (k%(i*2)/i==1){
			k=k-i; x=g[j][x]; 
		}
		i=i*2; j++;
	}
	return x;
}
int main(){
	n=read(); q=read();
	for (i=1;i<=n;i++){
		a[i]=read();
	}
	for (i=1;i<n;i++){
		x=read(); y=read(); z=read();
		add(x,y,z); add(y,x,z);
	}
	dfs(1,0); ans[1]=dp[1];
	for (i=2;i<=n;i++){
		ans[i]=dfs2(i,0);
	}
	dfs1(1,0);
	for (i=1;i<=q;i++){
		x=read(); y=read();
		if (x==y){
			printf("%I64d\n",ans[x]); continue;
		}
		z=lca(x,y);
		if (z==y) swap(x,y);
		if (x==z){
			z=getkth(y,dept[y]-dept[x]-1);
			anss=tot[y]-tot[z];
			anss=anss+dp[z];
			anss=anss-f3[gg[z]];
			if (-f3[gg[z]]*2+dp[z]>=0) anss=anss+ans[x]-(-f3[gg[z]]*2+dp[z]);
			else anss=anss+ans[x];
			printf("%I64d\n",anss);
		}
		else{
			xx=getkth(x,dept[x]-dept[z]-1);
			yy=getkth(y,dept[y]-dept[z]-1);
			anss=0;
			anss=anss+tot[x]-tot[xx];
			anss=anss+tot[y]-tot[yy];
			anss=anss+dp[xx];
			anss=anss+dp[yy];
			anss=anss-f3[gg[xx]]-f3[gg[yy]];
			anss=anss+ans[z];
			if (-f3[gg[xx]]*2+dp[xx]>=0) anss=anss-(-f3[gg[xx]]*2+dp[xx]);
			if (-f3[gg[yy]]*2+dp[yy]>=0) anss=anss-(-f3[gg[yy]]*2+dp[yy]);
			printf("%I64d\n",anss);
		}
	}
	return 0;
}