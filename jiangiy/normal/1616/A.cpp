#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		int n,x;
		std::map<int,int>f;
		scanf("%d",&n);
		while(n--)scanf("%d",&x),f[std::abs(x)]++;
		int ans=0;
		for(auto&o:f) if(o.fi==0)ans++;
		else ans+=std::min(2,o.se);
		printf("%d\n",ans);
	}
}