#include<bits/stdc++.h>
using namespace std;
int n,tot,upperlim,fa[55],sz[55],bel[55],id[55],e[55],Log2[8500000];
char s[55][55]; int f[8500000],g[8500000],c[8500000];
void FWT_or(int *c,int n){
	for (int i=0;i<n;i++)
		for (int s=0;s<=upperlim;s++)
			if (!(s&(1<<i))) c[s|(1<<i)]+=c[s];
}
int findset(int u){
	if (u!=fa[u]) fa[u]=findset(fa[u]);
	return fa[u];
}
void Union(int x,int y){
	x=findset(x); y=findset(y);
	if (x==y) return;
	fa[y]=x; sz[x]+=sz[y];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for (int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for (int j=1;j<=n;j++)
			if (s[i][j]=='A') Union(i,j);
	}
	for (int i=1;i<=n;i++) id[i]=-1;
	for (int i=1;i<=n;i++){
		bel[i]=findset(i);
		if (i==bel[i]&&sz[i]>1) id[bel[i]]=tot++;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (s[i][j]=='X')
				if (bel[i]==bel[j]){
					puts("-1");
					return 0;
				}
				
	if (!tot){ printf("%d\n",n-1); return 0;}
	upperlim=(1<<tot)-1;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (id[bel[i]]!=-1&&id[bel[j]]!=-1&&s[i][j]=='X'){
				e[id[bel[i]]]|=(1<<id[bel[j]]);
				e[id[bel[j]]]|=(1<<id[bel[i]]);
			}
	for (int i=0;i<tot;i++) Log2[1<<i]=i;
	f[0]=1;
	for (int s=1;s<=upperlim;s++){
		int x=Log2[s&-s];
		if (!(e[x]&s)) f[s]=f[s^(s&-s)];
	}
	if (f[upperlim]){ printf("%d\n",n); return 0;}
	FWT_or(f,tot); c[0]=1;
	for (int s=1;s<=upperlim;s++) c[s]=(s&1)?-c[s>>1]:c[s>>1];
	for (int s=0;s<=upperlim;s++) g[s]=f[s];
	int ans=n;
	while (true){
		ans++;
		for (int s=0;s<=upperlim;s++) f[s]*=g[s];
		int res=0;
		for (int s=0;s<=upperlim;s++) res+=c[s]*f[upperlim^s];
		if (res) break;
	}
	printf("%d\n",ans);
	return 0;
}