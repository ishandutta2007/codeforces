#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		int n,k;
		scanf("%d%d",&n,&k);
		if(n+1<k*2){
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i%2==1&&i==j&&k){
					k--;
					putchar('R');
				}
				else{
					putchar('.');
				}
			}
			putchar('\n');
		}
	}
}