#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
const int N=1e6+10;
const double eps=1e-6;
const LL sed=1e9+7;
const LL P=998244353;
const LL INF=2e18;
LL qpow(LL x,LL y){
	LL re=1;
	x=x%P;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}

LL fac[N+10],inv[N+10];
void init(){
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(LL i=2;i<=N;++i){
		fac[i]=fac[i-1]*i%P;
	}
	inv[N]=qpow(fac[N],P-2);
	for(LL i=N;i>1;--i){
		inv[i-1]=inv[i]*i%P;
	}
	return;
}
set<int> S;
set<int>::iterator it;
int n;
int a[N];
void MAIN(){
	int x;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	S.clear();
	a[0]=0;
	for(int i=1;i<=n;++i){
		if(a[i]!=a[i-1]){
			S.insert(a[i]);
		}
	}
	int ans=0,now;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&a[j+1]==a[i]) ++j;
		now=j-i+1;
		x=a[i]+1;
		while(1){
			it=S.lower_bound(x);
			if(it==S.end()) break;
			++now;
			x=((*it)-a[i])*2+a[i];
		}
		ans=max(ans,now);
	}
	printf("%d\n",n-ans);
	return;
}
int main(){
	int ttt=1;scanf("%d",&ttt);
	while(ttt--){
		MAIN();
	}
    return 0;
}