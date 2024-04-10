#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,a[110000],f[110000];
int main(){
	scanf("%lld",&n);
	ll sum=0;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	ll now=0;
	for (int i=n;i>=1;i--){
    	f[i]=max(now-1,a[i]);
    	now=f[i];
	}
    ll ans=0;
    for (int i=1;i<=n;i++){
       now=max(now,f[i]);
       ans+=now;
    }
    printf("%lld\n",ans-sum);
	return 0;
}