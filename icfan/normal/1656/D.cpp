#include <cstdio>
typedef long long ll;
ll n;
void solve(){
	scanf("%lld",&n);
	if(n&1){
		puts("2");
		return;
	}
	ll val_1=2,val_2=n;
	while(val_2%2==0){
		val_2/=2;
		val_1*=2;
	}
	if((__int128)val_1*(val_1+1)<=2ll*n){
		printf("%lld\n",val_1);
	}
	else if(val_2!=1&&(__int128)val_2*(val_2+1)<=2ll*n){
		printf("%lld\n",val_2);
	}
	else{
		puts("-1");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}