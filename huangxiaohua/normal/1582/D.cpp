#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res;
ll a[100500];

void chk(ll x,ll y,ll z){
	ll sb,a,b,c=1;
	
	sb=x+y;
	if(sb){
		a=1;b=1;
		a*=z;b*=z;c*=-sb;
		printf("%lld %lld %lld",a,b,c);return;
	}
	
	sb=x-y;
	if(sb){
		a=1;b=-1;
		a*=z;b*=z;c*=-sb;
		printf("%lld %lld %lld",a,b,c);return;
	}
}

int main(){
	cin.tie(0);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(!(n&1)){
			for(i=1;i<=n;i++){
				if(i&1){
					printf("%lld ",a[i+1]);
				}
				else{
					printf("%lld ",-a[i-1]);
				}
			}
			puts("");continue;
		}
		else{
			for(i=1;i<=n-3;i++){
				if(i&1){
					printf("%lld ",a[i+1]);
				}
				else{
					printf("%lld ",-a[i-1]);
				}
			}
			chk(a[n-2],a[n-1],a[n]);
			puts("");continue;
		}
	}
}