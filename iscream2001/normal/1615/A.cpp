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
const LL INF=1e11;

void init(){
}

int n,m;
int a[N]; 
void MAIN(){
	int s=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s+=a[i];
	}
	if(s%n==0){
		puts("0");
	}
	else{
		puts("1");
	}
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