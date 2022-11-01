#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		int n,ans=0;
		scanf("%d",&n);
		while(n)ans=std::max(ans,n%10),n/=10;
		printf("%d\n",ans);
	}
}