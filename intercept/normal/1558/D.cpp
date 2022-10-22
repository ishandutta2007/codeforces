#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=4e5+9;
int n,m,a[M],x[M],y[M];
int fac[M],inv[M];
void add(int i,int p){
	for(;i<M;i+=i&-i)a[i]+=p;
}
int kth(int p,int rex=0){
	for(int i=1<<19;i;i>>=1)
		if(rex+i<M&&a[rex+i]<p)p-=a[rex+=i];
	return rex+1;
}
int c(int l,int r){
	return 1ll*fac[l]*inv[r]%mod*inv[l-r]%mod;
}
vector<int>v;
void work(){
	int k=0;
	v.clear();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=m;i>=1;--i){
		int l=kth(y[i]),r=kth(y[i]+1);
		if(l==r-1)k++;
		add(l,-1);
		v.push_back(l);
	}
	for(auto o:v)add(o,1);
	printf("%d\n",c(n*2-1-k,n-1-k));
}
int main(){
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<M;++i)fac[i]=1ll*fac[i-1]*i%mod,add(i,1);
	for(int i=2;i<M;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<M;++i)inv[i]=1ll*inv[i-1]*inv[i]%mod;
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}