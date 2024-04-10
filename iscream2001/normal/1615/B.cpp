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

int F[N][22];
void init(){
	int x;
	for(int i=1;i<=200000;++i){
		x=i;
		for(int j=0;j<=20;++j){
			F[i][j]=F[i-1][j]+(x&1);
			x>>=1;
		}
	}
}

int n,m;
int a[22];

void MAIN(){
	int l,r,ans,sum;
	scanf("%d%d",&l,&r);
	sum=ans=r-l+1;
	for(int j=0;j<=20;++j){
		a[j]=F[r][j]-F[l-1][j];
		ans=min(ans,sum-a[j]);
	}
	printf("%d\n",ans);
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