#include <cstdio>
#include <algorithm>

int t,n,k,a[200001];
long long S[200001];
long long f(int l,int r){
	return S[r]-S[l-1]+1ll*k*(r-l+1)-(1ll*(r-l+1)*(r-l+2))/2ll;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)scanf("%d",a+i),S[i]=S[i-1]+a[i];
		long long ans=0;
		for(int i=1;i<=n;++i)
			ans=std::max(ans,f(i,std::min(i+k-1,n)));
		printf("%lld\n",ans);
	}
}