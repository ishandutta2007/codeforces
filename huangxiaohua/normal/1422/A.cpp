#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,i,j,t,a[4];

int main(){
	scanf("%lld",&t);
	while(t--){
		
		scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
		printf("%lld\n",a[2]+a[3]+a[1]-1);
	}
}