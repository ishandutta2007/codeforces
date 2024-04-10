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
int a[N]; 
void MAIN(){
	scanf("%d%d",&n,&K);
	int u=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		u+=a[i];
	}
	if(u==K){
		puts("NO");
		return;
	}
	u=0;
	for(int i=1;i<=n;++i){
		if(u+a[i]==K) swap(a[i],a[i+1]);
		u+=a[i];
	}
	puts("YES");
	for(int i=1;i<=n;++i){
		printf("%d ",a[i]);
	} 
	puts("");
	return;
}

int main(){
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}