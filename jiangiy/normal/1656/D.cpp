#include<bits/stdc++.h>
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
using namespace std;
int s[200005];
LL solve(LL n){
	for(LL k=2;k<=(1ll<<31);k<<=1){
		LL low=k*(k+1)/2;
		if(n>=low&&(n-low)%k==0)return k;
	}
	for(LL k=3;k<=17;k+=2){
		LL low=k*(k+1)/2;
		if(n<low)break;
		if((n-low)%k==0)return k;
	}
	LL n0=n;
	while(n0%2==0)n0>>=1;
	if(n0==1)return-1;
	LL k=3;
	if(n0>=(1ll<<31)||(n0*(n0+1)/2>n)){
		while(n0%k!=0&&k*k<=n0)k+=2;
		if(n%k!=0)k=n0;
	}
	else{
		k=n0;
	}
	if(k>=(1ll<<31))return-1;
	LL low=k*(k+1)/2;
	if(n>=low&&(n-low)%k==0)return k;
	return-1;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL n;
		scanf("%lld",&n);
		printf("%lld\n",solve(n));
	}
}