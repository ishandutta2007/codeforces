#include<bits/stdc++.h>
#define LL long long
#define DB double
using namespace std;
const int N=1e5+10;
const LL P=998244353;
LL qpow(LL x,LL y){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
LL fac[N<<1],inv[N<<1];
LL C(int x,int y){
	if(x<y) return 0;
	return fac[x]*inv[x-y]%P*inv[y]%P; 
}
int n,m;
struct Node{
	int l,r;
}a[100],b[100];
int mu[N+10];
bool is_pri[N+10];
int pri[N],cntp=0;
void init_pri(){
	mu[1]=1;
    for(int i=2;i<=N;++i){
        if(!is_pri[i]) {
        	mu[i]=-1;
            pri[++cntp]=i;
        }
        for(int j=1;j<=cntp&&pri[j]*i<=N;++j){
            is_pri[pri[j]*i]=1;
            if(i%pri[j]==0) {
            	mu[pri[j]*i]=0;
                break;
            }
            else{
            	mu[pri[j]*i]=-mu[i];
			}
        }
    }
}
int dp[100005],g[100005];
LL F(int K){
	int S=m/K;
	for(int i=1;i<=n;++i){
		b[i].r=a[i].r/K;
		if(a[i].l%K==0){
			b[i].l=a[i].l/K;
		}
		else b[i].l=(a[i].l/K)+1;
		if(b[i].l>b[i].r||b[i].l>S){
			return 0;
		}
		S-=b[i].l;
		b[i].r-=b[i].l;
	}
	for(int j=0;j<=S;++j){
		dp[j]=0;
	}
	dp[0]=1;
	int x;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=S;++j) g[j]=0;
		x=b[i].r+1;
		for(int j=0;j<=S-x;++j){
			g[j+x]=-dp[j];
		}
		for(int j=0;j<=S;++j) {
			dp[j]+=g[j];
			if(dp[j]<0) dp[j]+=P;
		}
	}
	LL re=0;
	for(int j=0;j<=S;++j){
		re+=(LL)dp[j]*C(S-j+n,n)%P;
	}
	re=re%P;
	return re;
}
void MAIN(){
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(LL i=2;i<=200000;++i){
		fac[i]=fac[i-1]*i%P;
	}
	inv[200000]=qpow(fac[200000],P-2);
	for(LL i=200000;i>1;--i){
		inv[i-1]=inv[i]*i%P;
	}
	init_pri();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	LL ans=0,re;
	for(int i=1;i<=m;++i){
		if(!mu[i]) continue;
		re=F(i);
		if(mu[i]>0) ans+=re;
		else ans-=re;
	}
	ans=(ans%P+P)%P;
	printf("%lld\n",ans);
    return;
}
int main(){
    int ttt=1;
    while(ttt--){
        MAIN();
    }
    return 0;
}