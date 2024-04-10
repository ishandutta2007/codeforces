#include<stdio.h>
#include<algorithm>
#define inf 1000000000000000000
using namespace std;
const int maxn=1000005;
int n,ql,qr;
int q[maxn];
long long ans;
long long f[maxn];
struct Rectangle{
	int x,y;
	long long v;
}r[maxn];
inline int cmp(Rectangle a,Rectangle b){
	return a.x<b.x;
}
inline int x(int p){
	return r[p].x;
}
inline long long y(int p){
	return f[p];
}
inline long double slope(int a,int b){//a>b,a is better than b
	return x(a)==x(b)? (y(a)>=y(b)? 1.0*inf:-1.0*inf):(1.0*(y(a)-y(b))/(x(a)-x(b)));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%lld",&r[i].x,&r[i].y,&r[i].v);
	sort(r+1,r+1+n,cmp);
	ql=1,qr=0,q[++qr]=0;
	for(int i=1;i<=n;i++){
		while(ql<qr&&slope(q[ql+1],q[ql])>=1.0*r[i].y)
			ql++;
		f[i]=f[q[ql]]+1ll*(r[i].x-r[q[ql]].x)*r[i].y-r[i].v;
		ans=max(ans,f[i]);
		while(ql<qr&&slope(q[qr],q[qr-1])<=slope(i,q[qr-1]))
			qr--;
		q[++qr]=i;
	}
	printf("%lld\n",ans);
	return 0;
}