#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int T;
ll n,m,g,b;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%lld%lld%lld",&n,&g,&b); m=(n+1)/2;
		printf("%lld\n",max(n,1ll*(m-1)/g*(g+b)+(m-1)%g+1));
	}
	return 0;
}