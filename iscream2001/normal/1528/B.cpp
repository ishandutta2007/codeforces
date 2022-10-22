#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ull unsigned long long
const int N=1e5+10;
const LL P=998244353;
void add(LL &x,LL y){
	x+=y;if(x>=P)x-=P;
}

void init(){
	return;
}
int n;
LL f[1000005];
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i)
			++f[j];
	LL sum=0;
	for(int i=1;i<=n;++i){
		add(f[i],sum);
		add(sum,f[i]);
	}
	printf("%lld\n",f[n]);
	return;
}
int main(){
	init();
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}