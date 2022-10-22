#include<bits/stdc++.h>
#pragma GCC optimize("-Ofast")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
char buf[1<<20],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1,c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0',c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5;
int n,x[maxn],y[maxn],c[maxn];
int ord[maxn],p[3]={1,2,3};
vector<int> qx[maxn],qy[maxn],rx[maxn],ry[maxn];
#define lc k<<1
#define rc lc|1
#define mid (l+r>>1)
struct segm{
	int mx[maxn<<2],ad[maxn<<2],t[maxn],X,Y,V;
	inline void chg(int k,int v){
		mx[k]+=v,ad[k]+=v;
	}
	inline void pdown(int k){
		if(ad[k])chg(lc,ad[k]),chg(rc,ad[k]),ad[k]=0;
	}
	void upd(int k=1,int l=0,int r=n+1){
		if(l>=X&&r<=Y)return chg(k,V);
		pdown(k);
		if(mid>=X)upd(lc,l,mid);
		if(mid<Y)upd(rc,mid+1,r);
		mx[k]=mx[rc];
	}
	inline void modify(int x,int y,int v){
		X=x,Y=y,V=v,upd();
	}
	inline int query1(int x){
		int k=1,l=0,r=n+1;
		while(l!=r){
			pdown(k);
			x<=mid?(r=mid,k=lc):(l=mid+1,k=rc);
		}
		return mx[k];
	}
	inline int query2(){
		int k=1,l=0,r=n+1;
		while(l!=r){
			pdown(k),k<<=1;
			mx[k]>=0?r=mid:(l=mid+1,++k);
		}
		return r;
	}
}rt1,rt2;
int X,Y,V;
void UPD(int k=1,int l=0,int r=n+1){
	if(l>=X&&r<=Y)return rt1.chg(k,V),rt2.chg(k,V);
	rt1.pdown(k),rt2.pdown(k);
	if(mid>=X)UPD(lc,l,mid);
	if(mid<Y)UPD(rc,mid+1,r);
	rt1.mx[k]=rt1.mx[rc],rt2.mx[k]=rt2.mx[rc];
}
inline void MDF(int x,int y,int v){X=x,Y=y,V=v,UPD();}
inline int Q1(int x){
	int k=1,l=0,r=n+1;
	while(l!=r){
		rt1.pdown(k),rt2.pdown(k),k<<=1;
		x<=mid?r=mid:(l=mid+1,++k);
	}
	return rt2.mx[k]-rt1.mx[k];
}
int ans=0;
inline void solve(int* x,vector<int>* qx,int* y){
	for(int i=1;i<=n;i++)
		if(c[i]==p[1])MDF(y[i],n+1,1);
		else if(c[i]==p[2])rt1.modify(0,y[i]-1,-1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int u:qx[i]){
			if(c[u]==p[0])cnt++;
			else if(c[u]==p[1])MDF(y[u],n+1,-1);
			else rt1.modify(0,y[u]-1,1);
		}
		int u=rt1.query2(),res=Q1(u);
		if(u)res=max(res,rt2.query1(u-1));
		ans=max(ans,min(cnt,res));
	}
}
int xx[maxn],yy[maxn];
int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		x[i]=readint();
		y[i]=readint();
		c[i]=readint();
	}
	for(int i=1;i<=n;i++) ord[i]=x[i];
	sort(ord+1,ord+n+1);
	for(int i=1;i<=n;i++) x[i]=lower_bound(ord+1,ord+n+1,x[i])-ord;
	for(int i=1;i<=n;i++){
		qx[x[i]].push_back(i);
		rx[n+1-x[i]].push_back(i);
	}
	for(int i=1;i<=n;i++) ord[i]=y[i];
	sort(ord+1,ord+n+1);
	for(int i=1;i<=n;i++) y[i]=lower_bound(ord+1,ord+n+1,y[i])-ord;
	for(int i=1;i<=n;i++){
		xx[i]=n+1-x[i],yy[i]=n+1-y[i];
		qy[y[i]].push_back(i);
		ry[n+1-y[i]].push_back(i);
	}
	do{
		solve(x,qx,x);
		solve(x,qx,y);
		solve(y,qy,x);
		solve(y,qy,y);
		solve(xx,rx,yy);
		solve(yy,ry,xx);
	}while(next_permutation(p,p+3));
	printf("%d\n",ans*3);
	return 0;
}