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
LL C(LL x,LL y){
	if(x<y) return 0;
	return fac[x]*finv[y]%M*finv[x-y]%M;
}
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
char s[100005][4];
void MAIN(){
	LL X=0,Y=0,Z;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]);
		for(int j=0;j<2;++j){
			if(s[i][j]=='B') ++X;
			if(s[i][j]=='W') ++Y;
		}
	}
	if(X>n||Y>n){
		puts("0");
		return;
	}
	LL ans=C(n+n-X-Y,n-X),now=1;
	for(int i=1;i<=n;++i){
		Z=0;
		if(s[i][0]!='B'&&s[i][1]!='W') ++Z;
		if(s[i][0]!='W'&&s[i][1]!='B') ++Z;
		now=now*Z%M;
	}
	ans-=now;
	now=1;
	for(int i=1;i<=n;++i){
		Z=0;
		if(s[i][0]!='B'&&s[i][1]!='W') ++Z;
		now=now*Z;
	}
	ans+=now;
	now=1;
	for(int i=1;i<=n;++i){
		Z=0;
		if(s[i][0]!='W'&&s[i][1]!='B') ++Z;
		now=now*Z;
	}
	ans+=now;
	ans=(ans%M+M)%M;
	printf("%lld\n",ans);
	return;
}
//Diaspora
//flex-block
//git config --global init.defaultBranch main
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	init();
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}