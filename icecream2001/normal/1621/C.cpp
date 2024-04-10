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
const int INF=2e9;
void init(){
}

int n,K,m;
int vis[N];
int q[N];
int ans[N];
void check(int x){
	int l=1,r=0;
	while(1){
		printf("? %d\n",x);
		fflush(stdout);
		++r;
		scanf("%d",&q[r]);
		if(vis[q[r]]==0){
			vis[q[r]]=1;
		}
		else{
			break;
		}
	}
	--r;
	while(q[l]!=x){
		q[++r]=q[l];
		++l;
	}
	for(int i=l;i<r;++i){
		ans[q[i]]=q[i+1];
	}
	ans[q[r]]=q[l];
	return;
}
void MAIN(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=100000;++i) fac[i]=fac[i-1]*i%P;
//	finv[100000]=qpow(fac[100000],P-2,P);
//	for(LL i=100000;i>1;--i) finv[i-1]=finv[i]*i%P;
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		vis[i]=0;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]==0){
			check(i);
		}
	}
	printf("!");
	for(int i=1;i<=n;++i) printf(" %d",ans[i]);
	
	puts("");
	fflush(stdout);
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