#include<bits/stdc++.h>
#define LD double
#define LL long long
using namespace std;
const LL INF=1e18;
const LD PI=acos(-1.0);
const LL M=1e9+7;
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
int mu[N+10];
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
}used;

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

int n,Q;
multiset<int> S;
multiset<int>::iterator it;
multiset< pair<int,int> > T;
multiset< pair<int,int> >::iterator it2;
bool vis[200005];

bool sol(int x){
	int l=x,r=x;
	it=S.lower_bound(x);
	if(it!=S.begin()){
		--it;
		l=(*it);
	}
	else l=0;
	++l;
	it=S.upper_bound(x);
	if(it!=S.end()){
		r=(*it);
	}
	else r=n+1;
	--r;
	it2=T.lower_bound(make_pair(l,0));
	if(it2==T.end()||(*it2).first>x){
		return 0;
	}
	pair<int,int> tmp=*it2;
	if(tmp.second<=r) return 1;
	return 0;
	
}
void MAIN(){
	cin>>n>>Q;
	int op,l,r,x,y;
	for(int i=1;i<=n;++i){
		S.insert(i);
	}
	while(Q--){
		cin>>op;
		if(op==0){
			cin>>l>>r>>x;
			if(x==0){
				it=S.lower_bound(l);
				while(it!=S.end()&&(*it)<=r){
					S.erase(it);
					it=S.lower_bound(l);
				}
			}
			else{
				bool flag=1;
				pair<int,int> tmp;
				while(flag){
					flag=0;
					it2=T.lower_bound(make_pair(l,1000000));
					if(it2!=T.begin()){
						--it2;
						tmp=*it2;
						if(tmp.second>=r){
							T.erase(it2);
							flag=1;
						}
					}
				}
				it2=T.lower_bound(make_pair(l,0));
				flag=1;
				if(it2!=T.end()){
						tmp=*it2;
						if(tmp.second<=r){
							
							flag=0;
						}
				}
				if(flag){
					T.emplace(make_pair(l,r));
				}
			}
		}
		else{
			cin>>l;
			it=S.lower_bound(l);
			if(it==S.end()||(*it)!=l){
				cout<<"NO\n";
				continue;
			}
			y=(*it);
			if(sol(y)) cout<<"YES\n";
			else cout<<"N/A\n";
		}
	}
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