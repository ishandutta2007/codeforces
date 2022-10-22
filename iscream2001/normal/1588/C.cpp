#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const LD PI=acos(-1.0);
const LL M=1e9+7;
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

struct jz{
	LL x[10][10];
};
jz operator * (jz A,jz B){
	jz C;
	for(int i=1;i<=6;++i){
		for(int j=1;j<=6;++j){
			C.x[i][j]=0;
		}
	}
	for(int i=1;i<=6;++i){
		for(int k=1;k<=6;++k){
			if(A.x[i][k]!=0){
				for(int j=1;j<=6;++j){
					C.x[i][j]+=A.x[i][k]*B.x[k][j];
				}
			}
		}
	}
	return C;
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



struct P{
	LD x,y;
	P(LD _x=0,LD _y=0){x=_x;y=_y;}
}used;

LD dis(P x){return x.x*x.x+x.y*x.y;}
P operator + (P x,P y){return P(x.x+y.x,x.y+y.y);}
P operator - (P x,P y){return P(x.x-y.x,x.y-y.y);}
LD operator * (P x,P y){return x.x*y.x+x.y*y.y;}
LD operator / (P x,P y){return x.x*y.y-x.y*y.x;}

vector<LD> V[70];

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

int n;
LL a[N];

struct node{
	LL x,y;
};
bool operator < (node x,node y){
	return x.x<y.x;
} 
multiset<node> S;
multiset<node>::iterator it;
LL add,fff;
void ins(LL x){
	x-=add;
	x*=fff;
	it=S.lower_bound((node){x,0LL});
	if(it==S.end()){
		S.insert((node){x,1LL});
		return;
	}
	node tmp=(*it);
	if(tmp.x==x){
		S.erase(it);
		tmp.y++;
		S.insert(tmp);
		return;
	}
	S.insert((node){x,1LL});
	return;
}
void del(){
	node tmp;
	if(fff==1){
		while(S.begin()!=S.end()){
			it=S.begin();
			tmp=(*it);
			if(tmp.x+add<0LL){
				S.erase(it);
				continue;
			}
			break;
		}
		return;
	}
	if(fff==-1){
		while(S.begin()!=S.end()){
			it=S.end();
			--it;
			tmp=(*it);
			if(-tmp.x+add<0LL){
				S.erase(it);
				continue;
			}
			break;
		}
		return;
	}
}
LL find(){
	LL re=0;
	LL x=0;
	x-=add;
	x*=fff;
	it=S.lower_bound((node){x,0LL});
	if(it==S.end()){
		return re;
	}
	node tmp=(*it);
	if(tmp.x==x){
		return tmp.y;
	}
	return re;
}
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	S.clear();add=0;fff=1;
	LL ans=0;
	for(int i=1;i<=n;++i){
		ins(0LL);
		fff=-fff;
		add=-add;
		add+=a[i];
		del();
		ans+=find();
	}
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
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}