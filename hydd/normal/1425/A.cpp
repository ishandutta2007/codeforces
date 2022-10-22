#include<cstdio>
using namespace std;
typedef long long ll;
int T; ll n;
ll solve(ll n){
	if (n==0) return 0;
	if (n==4) return 3;
	if (n&1) return n-solve(n-1);
	if (n&3) return n-solve(n>>1);
	else return n-solve(n-1);
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%lld",&n);
		printf("%lld\n",solve(n));
	}
	return 0;
}