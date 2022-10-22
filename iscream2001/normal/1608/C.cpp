#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const LD PI=acos(-1.0);
const LL M=998244353;
const int N=3e5+10;
const LD eps=1e-8;

LL qpow(LL x,LL y,LL mod=M){
	x%=mod;
	LL re=1;
	while(y){
		if(y&1) re=re*x%mod;
		y>>=1;x=x*x%mod;
	}
	return re;
}

//inline char gc(){return getchar();}
bool is_pri[N+10];
LL pri[6000000];
int cntp=0;

void init_pri(){
    for(int i=2;i<=N;++i){
        if(!is_pri[i]) {
            pri[++cntp]=i;
        }
        for(int j=1;j<=cntp&&pri[j]*i<=N;++j){
            is_pri[pri[j]*i]=1;
            if(i%pri[j]==0) {
                break;
            }
            else{
			}
        }
    }
}

LL fac[1000005],finv[1000005];

void init(){
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%M;
	finv[1000000]=qpow(fac[1000000],M-2,M);
	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%M;
	return;
}

struct P{
	LD x,y;
	P(LD _x=0,LD _y=0){x=_x;y=_y;}
}used;

LD dis(P x){return x.x*x.x+x.y*x.y;}
P operator + (P x,P y){return P(x.x+y.x,x.y+y.y);}
P operator - (P x,P y){return P(x.x-y.x,x.y-y.y);}
LD operator * (P x,P y){return x.x*y.x+x.y*y.y;}
LD operator / (P x,P y){return x.x*y.y-x.y*y.x;}
int n;

struct node{
	int x,id;
}a[100005],b[100005];
bool cmp(node x,node y){
	return x.x>y.x;
}
int rk[100005];
int A[100005],B[100005]; 
bool vis[100005];
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){scanf("%d",&a[i].x);a[i].id=i;}
	for(int i=1;i<=n;++i){scanf("%d",&b[i].x);b[i].id=i;}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;++i){
		rk[a[i].id]=i;
	}
	for(int i=1;i<=n;++i){
		B[i]=rk[b[i].id];
	}
	for(int i=1;i<=n;++i){
		rk[b[i].id]=i;
	}
	for(int i=1;i<=n;++i){
		A[i]=rk[a[i].id];
	}
	for(int i=2;i<=n;++i){
		A[i]=max(A[i],A[i-1]);
		B[i]=max(B[i],B[i-1]);
	}
	int X=1,Y=1;
	bool flag=1;
	while(flag){
		flag=0;
		if(A[X]>Y){
			flag=1;
			Y=A[X];
			continue;
		}
		if(B[Y]>X){
			flag=1;
			X=B[Y];
			continue;
		}
	}
	for(int i=1;i<=n;++i) vis[i]=0;
	for(int i=1;i<=X;++i) {
		vis[a[i].id]=1;
	}
	for(int i=1;i<=Y;++i){
		vis[b[i].id]=1;
	}
	for(int i=1;i<=n;++i) putchar('0'+vis[i]);
	puts("");
	return;
}
//Diaspora
//flex-block
//git config --global init.defaultBranch main
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	init();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}