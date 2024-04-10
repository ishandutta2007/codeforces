#include<bits/stdc++.h>
#define fi first
#define se second
#define ULL unsigned long long
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL x;
		scanf("%lld",&x);
		if(x%2050){
			puts("-1");
			continue;
		}
		x/=2050;
		int ans=0;
		while(x)ans+=x%10,x/=10;
		printf("%d\n",ans);
	}
}