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
struct Node{
	int l,r,c;
}a[N];
int ans[N];
int L[N],R[N]; 
void MAIN(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=100000;++i) fac[i]=fac[i-1]*i%P;
//	finv[100000]=qpow(fac[100000],P-2,P);
//	for(LL i=100000;i>1;--i) finv[i-1]=finv[i]*i%P;
	
	scanf("%d",&n);
	L[0]=INF;
	R[0]=-INF;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].c);
		ans[i]=0;
		L[i]=L[i-1];R[i]=R[i-1];
		L[i]=min(L[i],a[i].l);
		R[i]=max(R[i],a[i].r);
	}
	int now=0;
	for(int i=1;i<=n;++i){
		if(L[i]!=L[i-1]){
			now=a[i].c;
			ans[i]+=now;
		}
		else{
			if(a[i].l==L[i]&&a[i].c<now){
				now=a[i].c;
			}
			ans[i]+=now;
		}
	}
	for(int i=1;i<=n;++i){
		if(R[i]!=R[i-1]){
			now=a[i].c;
			ans[i]+=now;
		}
		else{
			if(a[i].r==R[i]&&a[i].c<now){
				now=a[i].c;
			}
			ans[i]+=now;
		}
	}
	now=0;
	int ls=INF,rs=-INF;
	for(int i=1;i<=n;++i){
		if(ls==L[i]&&rs==R[i]){
			ans[i]=min(ans[i],now);
		}
		if(a[i].l==L[i]&&a[i].r==R[i]&&a[i].c<=ans[i]){
			ls=L[i];
			rs=R[i];
			now=a[i].c;
			ans[i]=now;
		}
	}
	for(int i=1;i<=n;++i) printf("%d\n",ans[i]);
	//printf("%lld\n",ans);
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