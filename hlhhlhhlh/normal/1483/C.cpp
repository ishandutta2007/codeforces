// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=300010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n;
int a[maxn];
long long b[maxn];
int ll[maxn*4],rr[maxn*4],mi[maxn*4];
void build(int x,int l,int r){
	int mid=(l+r)/2;
	ll[x]=l; rr[x]=r;
	if (l==r){
		mi[x]=l;
		return;
	}
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	if (a[mi[x*2]]<a[mi[x*2+1]]) mi[x]=mi[x*2]; else mi[x]=mi[x*2+1];
}
int getmi(int x,int l,int r){
	if ((l<=ll[x])&&(rr[x]<=r)) return mi[x];
	if ((rr[x]<l)||(r<ll[x])) return 0;
	int t1=getmi(x*2,l,r);
	int t2=getmi(x*2+1,l,r);
	if (a[t1]<a[t2]) return t1; else return t2;
}
struct node{
	long long l,r,thi;
	node (long long x=0,long long y=0,long long z=0){
		l=x; r=y; thi=z;
	}
}thi;
node solve(int l,int r){
	if (l>r){ return node(0,0,0); }
	int mi=getmi(1,l,r);
	node t1=solve(l,mi-1);
	node t2=solve(mi+1,r);
	node thi=node(0,0,0);
	thi.l=max(max((long long)0,t1.l),max((long long)0,t1.l)+b[mi]+max((long long)0,t2.thi));
	thi.r=max(max((long long)0,t2.r),max((long long)0,t2.r)+b[mi]+max((long long)0,t1.thi));
	thi.thi=max(max(max(t1.thi,(long long)0)+max(t2.thi,(long long)0)+b[mi],max(t1.thi,t2.thi)),(long long)0);
	if ((l==1)&&(r==n)){
		printf("%lld\n",b[mi]+t1.l+t2.r);
	}
	return thi;
}
int main(){
	n=read(); a[0]=(1e9)+10;
	for (i=1;i<=n;i++){
		a[i]=read();
	} 
	for (i=1;i<=n;i++){
		b[i]=read();
	}
	build(1,1,n);
	solve(1,n);
	return 0;
}