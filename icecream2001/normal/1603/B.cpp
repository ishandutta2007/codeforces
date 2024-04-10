#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=3e5+10;
int n,K;
int a[N];
void MAIN(){
	LL x,y;
	scanf("%lld%lld",&x,&y);
	if(y<x) {
		printf("%lld\n",x+y);
		return;
	}
	if(y%x==0){
		printf("%lld\n",x);
		return;
	}
	LL b=(y%x)/2;
	LL K=y/x;
	printf("%lld\n",K*x+b);
	return;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		MAIN();
	}
    return 0;
}