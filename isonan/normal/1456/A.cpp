#include <cstdio>
#include <algorithm>

int n,p,k,t,a[100001],x,y;
long long f[100001];
long long ans;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d%d",&n,&p,&k);
		for(int i=1;i<=n;i++)scanf("%1d",a+i);
		scanf("%d%d",&x,&y);
		ans=1e16;
		for(int i=n;i>=p;i--){
			if(i+k<=n)f[i]=f[i+k];
			else f[i]=0;
			if(!a[i])f[i]+=x;
			ans=std::min(ans,1ll*(i-p)*y+f[i]);
		}
		printf("%lld\n",ans);
	}
}