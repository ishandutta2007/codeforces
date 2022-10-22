#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
int a[Maxn+5];
int n;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a+1,a+1+n);
	ll sum=a[n];
	ll cur=a[1];
	for(int i=2;i<=n;i++){
		sum+=cur-1ll*(i-1)*a[i];
		cur+=a[i];
	}
	printf("%lld\n",sum);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}