#include<bits/stdc++.h>
#define double long double
#define LL long long
using namespace std;
const LL INF=1e18;
const double PI=acos(-1.0);
inline char gc(){return getchar();}
inline int read(){
    int f=1,c; 
	while (c=gc(),c<48||c>57) if (c=='-') f=-1; 
	int x=c-'0';
    while(c=gc(),c>47&&c<58) x=x*10+c-'0'; 
	return f>0?x:-x;
}
int n;

struct Node{
	int id;
	LL x;
}a[100005];
LL A,cf,cm,m;
bool cmpid(Node x,Node y){return x.id<y.id;}
bool cmpx(Node x,Node y){return x.x<y.x;}
LL sum[100005];
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d%lld%lld%lld%lld",&n,&A,&cf,&cm,&m);
	for(int i=1;i<=n;++i){
		a[i].id=i;
		a[i].x=read();
	}
	sort(a+1,a+1+n,cmpx);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i].x;
	}
	if(A*(LL)n-sum[n]<=m){
		printf("%lld\n",(LL)n*cf+A*cm);
		for(int i=1;i<=n;++i){
			printf("%lld ",A);
		}
		puts("");
		return 0;
	}
	LL las=m;
	LL hhh=0,ans=-1;
	LL l,r,mid;
	for(LL i=0;i<=n;++i){
		if(las<0) break;
		l=1;r=n-i;
		while(l!=r){
			mid=(l+r+1)>>1;
			if(mid*a[mid].x-sum[mid]<=las) l=mid;
			else r=mid-1;
		}
		r=(las-(l*a[l].x-sum[l]))/l;
		r=min(r,A-a[l].x);
		if((r+a[l].x)*cm+i*cf>ans){
			ans=(r+a[l].x)*cm+i*cf;
			hhh=i;
		}
		las-=(A-a[n-i].x);
	}
	las=m;
	for(int i=n;i>n-hhh;--i){
		las-=(A-a[i].x);
		a[i].x=A;
	}
	l=1;r=n-hhh;
	while(l!=r){
		mid=(l+r+1)>>1;
		if(mid*a[mid].x-sum[mid]<=las) l=mid;
		else r=mid-1;
	}
	r=(las-(l*a[l].x-sum[l]))/l;
	r=min(r,A-a[l].x);
	r+=a[l].x;
	for(int i=1;i<=l;++i){
		las-=(r-a[i].x);
		a[i].x=r;
	}
//	for(int i=1;i<=n;++i){
//		if(a[i].x==A) continue;
//		if(las==0) continue;
//		--las;
//		a[i].x++;
//	}
	sort(a+1,a+1+n,cmpid);
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i){
		printf("%lld ",a[i].x);
	}
	puts("");
	return 0;
}