#include <cstdio>
#include <algorithm>

int q,n,x,y,a,b;
long long k,p[200001];
int gcd(int a,int b){
	return (!b)?a:gcd(b,a%b);
}
int main(){
	scanf("%d",&q);
	for(int fd=1;fd<=q;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%I64d",p+i),p[i]/=100;
		scanf("%d%d%d%d%I64d",&x,&a,&y,&b,&k);
		std::sort(p+1,p+n+1);
		std::reverse(p+1,p+n+1);
		for(int i=1;i<=n;i++)p[i]+=p[i-1];
		long long lcm=(1ll*a*b)/gcd(a,b);
		bool cando=0;
		for(int i=1;i<=n;i++){
			int n1=(1ll*i/lcm),n2=(i/a)-n1,n3=(i/b)-n1;
			long long cnt;
			if(x>y)cnt=(p[n1])*(x+y)+(p[n1+n2]-p[n1])*x+(p[n1+n2+n3]-p[n1+n2])*y;
			else cnt=(p[n1])*(x+y)+(p[n1+n3]-p[n1])*y+(p[n1+n2+n3]-p[n1+n3])*x;
			if(cnt>=k){
				printf("%d\n",i);
				cando=1;
				break;
			}
		}
		if(!cando)puts("-1");
	}
}