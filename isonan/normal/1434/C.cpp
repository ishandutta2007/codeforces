#include <cstdio>
#include <algorithm>
#define int long long

int t;
int a,b,c,d;
long long f(int l,int r){
	return (r-l+1ll)*(l+r)/2ll;
}
signed main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(1ll*c*b-a<0){
			puts("-1");
			continue;
		}
		int l=0,r=1000000,mid,ans;
		while(l<=r){
			mid=(l+r)>>1;
			if(1ll*std::min(c,1ll*mid*d)*b-a<0)ans=mid,l=mid+1;
			else r=mid-1;
		}
//		printf("%lld\n",ans);
		long long sum=-1ll*(ans+1)*a; 
		int x=(c+d-1)/d;
		sum+=1ll*f(0,std::min(x,ans))*d*b;
		if(ans>=x)sum+=1ll*(ans-x+1)*c*b;
		printf("%lld\n",-sum);
	}
}