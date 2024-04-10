#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=1e6+10;

void init(){
}

int n;
int a[N];
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(i%2==1&&a[i]<0) a[i]=-a[i];
		if(i%2==0&&a[i]>0) a[i]=-a[i];
	}
	for(int i=1;i<=n;++i){
		printf("%d ",a[i]);
	}
	puts("");
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}