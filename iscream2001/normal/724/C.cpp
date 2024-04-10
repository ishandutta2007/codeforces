#include <cstdio>
#include <algorithm>
typedef long long LL;

const LL INF=1LL<<60;
int n,m,k;
LL mx;

int gcd(int a,int b) {
	return b?gcd(b,a%b):a;
}
int exgcd(int a,int b,int &x,int &y) {
	if(!b) {x=1,y=0;return a;}
	int d=exgcd(b,a%b,y,x);
	y-=a/b*x; return d;
}
LL solve(int dx,int dy) {
	int a=2*n,b=-2*m,c=dy-dx,x,y;
	int d=exgcd(a,b,x,y);
	if(c%d) return INF;
	a/=d,b/=d,c/=d,b=std::abs(b),x=(x*c%b+b)%b;
	LL ans=2LL*n*x+dx;
	if(ans<=0||ans>=mx) return INF;
	return ans;
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	mx=1LL*n*m/gcd(n,m);
	while(k--) {
		int x0,y0;
		scanf("%d%d",&x0,&y0);
		LL ans=INF;
		ans=std::min(ans,solve(+x0,+y0));
		ans=std::min(ans,solve(+x0,-y0));
		ans=std::min(ans,solve(-x0,+y0));
		ans=std::min(ans,solve(-x0,-y0));
		printf("%lld\n",ans==INF?-1:ans);
	}
	return 0;
}