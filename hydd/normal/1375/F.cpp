#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=1e11;
ll a[4]; int x;
int main(){
	scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
	puts("First"); fflush(stdout);
	printf("%lld\n",INF); fflush(stdout);
	scanf("%d",&x); a[x]+=INF;
	ll tmp=3*a[x]-a[1]-a[2]-a[3];
	printf("%lld\n",tmp); fflush(stdout);
	scanf("%d",&x); a[x]+=tmp;
	sort(a+1,a+4);
	printf("%lld\n",a[2]-a[1]);
	return 0;
}