#include<bits/stdc++.h>
#define LD double
#define LL long long
using namespace std;
const LL INF=1e18;
const LD PI=acos(-1.0);
const LL M=998244353;
const int N=1e6+10;
const LD eps=1e-6;

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
LL mu[N+10];
int cntp=0;

void init_pri(){
	mu[1]=1;
    for(int i=2;i<=N;++i){
        if(!is_pri[i]) {
            pri[++cntp]=i;
            mu[i]=-1;
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



struct P{
	LD x,y;
	P(LD _x=0,LD _y=0){x=_x;y=_y;}
}used,p[100005];

LD dis(P x){return x.x*x.x+x.y*x.y;}
P operator + (P x,P y){return P(x.x+y.x,x.y+y.y);}
P operator - (P x,P y){return P(x.x-y.x,x.y-y.y);}
LD operator * (P x,P y){return x.x*y.x+x.y*y.y;}
P operator * (P x,LD y){return P(x.x*y,x.y*y);}
LD operator / (P x,P y){return x.x*y.y-x.y*y.x;}
P operator / (P x,LD y){return P(x.x/y,x.y/y);}
P dwh(P x){LD w=sqrt(dis(x));return x/w;}

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

int n,K;

pair<LD,int> q[1000000];

bool check(LD rad){
	int cnt=0;
	P tmp,tmp2,tmp3;
	LD l,r;
	for(int i=1;i<=n;++i){
		if(dis(p[i])>rad*rad*4) continue;
		tmp=p[i]/(LD)2;
		tmp2=dwh(tmp);
		swap(tmp2.x,tmp2.y);tmp2.x=-tmp2.x;
	//	cout<<rad<<" "<<tmp2.x<<" "<<tmp2.y<<endl;
		LD w=rad*rad-dis(tmp);
		if(w<=0) w=0;
		else w=sqrt(w);
	//	cout<<rad<<" "<<w<<endl;
		tmp3=tmp+(tmp2*w);l=atan2(tmp3.y,tmp3.x);
	//	cout<<rad<<" "<<tmp3.x<<" "<<tmp3.y<<" "<<sqrt(dis(tmp3))<<endl;
		tmp3=tmp-(tmp2*w);r=atan2(tmp3.y,tmp3.x);
		
	//		cout<<rad<<" "<<l<<" "<<r<<endl;
		
		
		if(l>r) swap(l,r);
		if(r-l>=PI){
			l+=PI+PI;
			swap(l,r);
		}
		while(r<=PI*6){
			q[++cnt]=make_pair(l,-1);
			q[++cnt]=make_pair(r,1);
			l+=PI+PI;
			r+=PI+PI;
		}
	}
	sort(q+1,q+1+cnt);
	int now=0;
	for(int i=1;i<=cnt;++i){
		now-=q[i].second;
		if(now>=K) return 1;
	}
	return 0;
}

void MAIN(){
	cin>>n>>K;
	for(int i=1;i<=n;++i){
		cin>>p[i].x>>p[i].y;
		if(dis(p[i])==0){
			--K;--n;--i;
		}
	}
	if(K<=0){
		puts("0.0000000000");
		return;
	}
	LD l=0,r=200000,mid;
	while(r-l>eps){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%0.10lf\n",l);
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
//	init_pri();
	int ttt=1;//cin>>ttt; 
	while(ttt--) {
		MAIN();
	}
	return 0;
}