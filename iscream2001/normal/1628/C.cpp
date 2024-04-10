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
const LL INF=1e18;

LL fac[1000005],finv[1000005];

LL C(LL x,LL y){
	if(x<y) return 0;
	return fac[x]*finv[y]%P*finv[x-y]%P;
}

void init(){
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%P;
	finv[1000000]=qpow(fac[1000000],P-2,P);
	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%P;
}
int n;
bool vis[1005][1005];
int a[1005][1005];
int xx[4]={-1,0,1,0};
int yy[4]={0,1,0,-1};
void MAIN(){
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			vis[i][j]=0;
			scanf("%d",&a[i][j]);
		}
	}
	int nx,ny;
	for(int i=2;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(vis[i-1][j]==0){
				ans^=a[i][j];
				for(int k=0;k<4;++k){
					nx=i+xx[k];
					ny=j+yy[k];
					if(nx>n||nx<1||ny>n||ny<1) continue;
					vis[nx][ny]^=1;
				}
			}
		}
	}
	printf("%d\n",ans);
	return;
}
/*
*/
int main(){
	//cout<<qpow((LL)16,P-2,P)*(LL)150%P<<endl;
    init();
    int ttt=1;scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}