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

int n,m,cnt;
int a[1005];

const int M=10005;
LL A[21000],B[21000];

void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<21000;++i) A[i]=0;
	LL ans=0;
	for(int j=1;j<=n;++j){
		for(int i=0;i<21000;++i) B[i]=0;
		for(int i=0;i<21000;++i){
			if(A[i]){
				B[i+a[j]]=(B[i+a[j]]+A[i]>=P)?B[i+a[j]]+A[i]-P:B[i+a[j]]+A[i];
				B[i-a[j]]=(B[i-a[j]]+A[i]>=P)?B[i-a[j]]+A[i]-P:B[i-a[j]]+A[i];
			}
		}
		B[M+a[j]]=(B[M+a[j]]+1>=P)?B[M+a[j]]+1-P:B[M+a[j]]+1;
		B[M-a[j]]=(B[M-a[j]]+1>=P)?B[M-a[j]]+1-P:B[M-a[j]]+1;
		for(int i=0;i<21000;++i) A[i]=B[i];
		ans+=A[M];
	}
	ans=(ans%P+P)%P;
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