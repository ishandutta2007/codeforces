#include<bits/stdc++.h>

using namespace std;
#define LL long long
const int N=3e5+10;
const LL INF=1e18;
const LL P=998244353;
LL add(LL &x,LL y){
	x+=y;if(x>=P)x-=P;
}
int n,K; 
void MAIN(){
	//scanf("%d",&n);
	//while(n--){
		scanf("%d",&K);
		if(K%2==1){
			puts("NO");
			return;
		}
		K>>=1;
		int d=sqrt(K);
		if(d*d==K) {
			puts("YES");
			return;
		}
		if(K%2==1){
			puts("NO");
			return;
		}
		K>>=1;
		d=sqrt(K);
		if(d*d==K) {
			puts("YES");
			return;
		}
		puts("NO");
	//}
	return;
}

int main(){
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}