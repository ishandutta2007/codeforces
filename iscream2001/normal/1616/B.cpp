
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
const int N=3e5+10;
const LL INF=2e18;
void init(){
}

int n,K;
//LL fac[N],finv[N];
//LL C(LL x,LL y){
//	if(x<y) return 0;
//	return fac[x]*finv[y]%P*finv[x-y]%P; 
//}
char s[N];
int a[N];

int b[N];
void MAIN(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=100000;++i) fac[i]=fac[i-1]*i%P;
//	finv[100000]=qpow(fac[100000],P-2,P);
//	for(LL i=100000;i>1;--i) finv[i-1]=finv[i]*i%P;
	
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n==1){
		putchar(s[1]);
		putchar(s[1]);
		puts("");
		return;
	}
	if(s[1]<=s[2]){
		putchar(s[1]);
		putchar(s[1]);
		puts("");
		return;
	}
	int num=1;
	for(int i=1;i<n;++i){
		if(s[i]>=s[i+1]){
			num=i+1;
		}
		else{
			break;
		}
	}
	for(int i=1;i<=num;++i) putchar(s[i]);
	for(int i=num;i>=1;--i) putchar(s[i]);
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