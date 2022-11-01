#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL x,y;
		scanf("%lld%lld",&x,&y);
		LL d=y%x;
		LL n=y-d/2;
		if(x>y)n=x+y;
		assert(n%x==y%n);
		printf("%lld\n",n);
	}
}