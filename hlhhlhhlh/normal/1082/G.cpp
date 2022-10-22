#include<bits/stdc++.h>
using namespace std;
const long long maxn=4010;
const long long maxm=10010;
const long long inf=1e9+7;
const long long S=4007;
const long long T=4008;
long long f1[maxn],f2[maxm],f3[maxm],f4[maxm],r=0;
long long n,m,x,y,z,tot;
long long i,j,k;
long long a[maxn],dis[maxn],las[maxn];
long long b[maxn];
void bfs(){
	long long l=1,r=1,i; a[1]=S;
	for (i=0;i<maxn;i++) las[i]=f1[i];
	for (i=0;i<maxn;i++) dis[i]=inf; dis[S]=0;
	while (l<=r){
		if (a[l]==T) return;
		i=f1[a[l]];
		while (i!=0){
			if ((f3[i]>0)&&(dis[f2[i]]==inf)){
				dis[f2[i]]=dis[a[l]]+1; r++; a[r]=f2[i];
			}
			i=f4[i];
		}
		l++;
	}
}
long long dfs(long long x,long long w){
	if (x==T) return w;
	long long t=0,tt=0,i=las[x];
	while (i!=0){
		if ((f3[i]>0)&&(dis[f2[i]]==dis[x]+1)){
			t=dfs(f2[i],min(f3[i],w));
			w=w-t; tt=tt+t;
			f3[i]=f3[i]-t;
			if (i%2==1) f3[i+1]=f3[i+1]+t; else f3[i-1]=f3[i-1]+t;
			if (w==0) return tt;
		}
		i=f4[i]; las[x]=i;
	}
	return tt;
}
long long dinic(long long S,long long T){
	long long tot=0,t=-1;
	while (t!=0){
		bfs();
		t=dfs(S,inf);
		tot=tot+t;
	}
	return tot;
}
void add(long long x,long long y,long long w){
	r++; f2[r]=y; f3[r]=w; f4[r]=f1[x]; f1[x]=r;
	r++; f2[r]=x; f3[r]=0; f4[r]=f1[y]; f1[y]=r;
}
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read();
	for (i=1;i<=n;i++){
		b[i]=read();
		add(i,T,b[i]);
	}
	for (i=1;i<=m;i++){
		x=read(); y=read(); z=read();
		tot=tot+z;
		add(n+i,x,inf); add(n+i,y,inf);
		add(S,n+i,z);
	}
	tot=tot-dinic(S,T);
	printf("%I64d\n",tot);
	return 0;
}