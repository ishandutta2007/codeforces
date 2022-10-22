#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const LD PI=acos(-1.0);
const LL M=998244353;
const int N=1e6+10;
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

int n,m;
int a[310*310],b[310*310];

map<int,int> mp;

vector<int> V[310*310];
int it[310*310];

int t[310][310];

void add(int y,int x){
	while(x<=m){
		t[y][x]++;
		x+=x&-x;
	}
}
int ask(int y,int x){
	int re=0;
	while(x>0){
		re+=t[y][x];
		x-=x&-x;
	}
	return re;
}

void MAIN(){
	mp.clear(); 
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n*m);
	int cnt=0,ans=0;
	for(int i=1;i<=n*m;++i){
		if(mp[b[i]]==0){
			mp[b[i]]=++cnt;
		}
	}
	for(int i=1;i<=n*m;++i){
		b[i]=mp[b[i]];
		a[i]=mp[a[i]];
	}
	for(int i=1;i<=cnt;++i) {
		V[i].clear();
		it[i]=0;
	}
	for(int i=1,j;i<=n*m;i=j+1){
		j=i;
		while(j%m!=0&&b[j+1]==b[i]) ++j;
		for(int k=j;k>=i;--k){
			V[b[i]].push_back(k);
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=0;j<=m;++j) t[i][j]=0;
	int x,y,z;
	for(int i=1;i<=n*m;++i){
		z=V[a[i]][it[a[i]]];
		it[a[i]]++;
		y=(z+m-1)/m;
		x=z-(y-1)*m;
		ans+=ask(y,x);
		add(y,x);
	}
	cout<<ans<<"\n";
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
	int ttt=1;cin>>ttt; 
	while(ttt--) {
		MAIN();
	}
	return 0;
}