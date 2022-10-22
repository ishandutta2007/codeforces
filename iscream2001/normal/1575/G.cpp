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
int n;
int a[100005];

vector<int> V[100005],A[100005];

map<int,LL> mp;

LL cnt[100005],ans[100005];

int tp;
int q[100005];

void MAIN(){
	for(int i=1;i<=100000;++i){
		for(int j=i;j<=100000;j+=i){
			V[j].emplace_back(i);
		}
	}
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	//	a[i]=i;
		for(auto j : V[a[i]]){
			A[j].emplace_back(i);
		}
	}
	int E=100,mx,o;
	for(int i=1;i<=100000;++i){
		if(A[i].size()<=20){
			for(auto j : A[i]){
				for(auto k : A[i]){
			//		cout<<i<<" "<<j<<" "<<k<<endl;
					ans[i]+=__gcd(j,k);
				}
			}
		}
		else if(A[i].size()<5000){
			mp.clear();
			for(auto k : A[i]){
				for(auto j : V[k]){
					//cnt[j]++;
					mp[j]++;
				}
			}
			tp=0;
			for(auto j : mp){
				cnt[j.first]=j.second*j.second;
				q[++tp]=j.first;
			}
//			if(i<=10){
//				for(int j=1;j<=10;++j) cout<<cnt[j]<<" ";cout<<endl;
//				for(int j=1;j<=tp;++j) cout<<q[j]<<" ";cout<<endl;
//			}
			for(int j=1;j<=tp;++j){
				for(auto k : V[q[j]]){
					if(k!=q[j]){
						cnt[k]+=mu[q[j]/k]*cnt[q[j]];
					}
				}
			}
//			if(i<=10){
//				for(int j=1;j<=10;++j) cout<<cnt[j]<<" ";cout<<endl;
//				for(int j=1;j<=tp;++j) cout<<q[j]<<" ";cout<<endl;
//			}
			for(int j=1;j<=tp;++j){
				ans[i]+=1LL*q[j]*cnt[q[j]];
				cnt[q[j]]=0;
			}
		}
		else{
			mx=0;
			for(auto k : A[i]) mx=max(mx,k);
			
			for(auto k : A[i]){
				for(auto j : V[k]){
					cnt[j]++;
				}
			}
			for(int j=1;j<=mx;++j) cnt[j]=cnt[j]*cnt[j];
			for(int j=1;j<=mx;++j){
				if(cnt[j]==0) continue;
				for(int k=2;(o=k*j)<=mx;++k){
					if(mu[k]>0)
						cnt[j]+=cnt[o];
					if(mu[k]<0)
						cnt[j]-=cnt[o];
				}
				ans[i]+=1LL*j*cnt[j];
				cnt[j]=0;
			}
		}
	}
//	for(int j=1;j<=10;++j) cout<<ans[j]<<" ";cout<<endl;
	for(int j=1;j<=100000;++j) ans[j]%=M;
	LL Ans=0;
	for(int j=1;j<=100000;++j){
		if(ans[j]==0) continue;
		for(int k=2;(o=k*j)<=100000;++k){
			if(mu[k]>0)
				ans[j]+=ans[o];
			if(mu[k]<0)
				ans[j]-=ans[o];
		}
		Ans+=ans[j]%M*(LL)j%M;
	}
	Ans=(Ans%M+M)%M;
	cout<<Ans<<endl;
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
	init_pri();
	int ttt=1;//cin>>ttt; 
	while(ttt--) {
		MAIN();
	}
	return 0;
}