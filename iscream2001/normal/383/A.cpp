#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;x%=P;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=2e5+10;
const LL INF=2e18;
void init(){
}

int n,m;
int a[N]; 
void MAIN(){
	LL x=0,y=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		x+=(a[i]==0);
		y+=(a[i]==1);
	}
	LL ans=0;
	for(int i=1;i<=n;++i){
		if(a[i]==1){
			ans+=x;
		}
		else{
			x--;
		}
	}
	printf("%lld\n",ans);
	
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;//scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}