#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=5000;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
int n;
int a[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ll ans=Inf_ll;
	for(int i=1;i<=n;i++){
		ll lst=0;
		ll sum=0;
		for(int j=i-1;j>0;j--){
			sum+=lst/a[j]+1;
			lst=(lst/a[j]+1)*a[j];
		}
		lst=0;
		for(int j=i+1;j<=n;j++){
			sum+=lst/a[j]+1;
			lst=(lst/a[j]+1)*a[j];
		}
		ans=std::min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}