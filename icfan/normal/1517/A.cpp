#include <cstdio>
typedef long long ll;
ll d[20];
int main(){
	d[0]=2050;
	for(int i=1;i<=15;i++){
		d[i]=d[i-1]*10;
	}
	int T;
	scanf("%d",&T);
	while(T--){
		ll n;
		scanf("%lld",&n);
		int ans=0;
		for(int i=15;i>=0;i--){
			while(n>=d[i]){
				n-=d[i];
				ans++;
			}
		}
		if(n){
			puts("-1");
		}
		else{
			printf("%d\n",ans);
		}
	}
	return 0;
}