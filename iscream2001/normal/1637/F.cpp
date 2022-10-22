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
LL Ans;
LL h[N];

vector<int> V[N],son[N];


int fa[N];

LL sum[N],mx[N],gsum[N],gmx[N];

void dfs1(int x){
	sum[x]=gsum[x]=mx[x]=gmx[x]=0;
	for(int i=0;i<V[x].size();++i){
		if(V[x][i]!=fa[x]){
			fa[V[x][i]]=x;
			dfs1(V[x][i]);
			gsum[x]+=sum[V[x][i]];
			gmx[x]=max(gmx[x],mx[V[x][i]]);
		}
	}
	sum[x]=gsum[x];
	mx[x]=gmx[x];
	if(mx[x]<h[x]){
		sum[x]+=h[x]-mx[x];
		mx[x]=h[x];
	}
	return;
}

vector<LL> gm[N],gs[N];

void dfs2(int x,LL sss,LL mmm){
	gsum[x]+=sss;
	gmx[x]=max(gmx[x],mmm);
	sum[x]=gsum[x];
	mx[x]=gmx[x];
	if(mx[x]<h[x]){
		sum[x]+=h[x]-mx[x];
		mx[x]=h[x];
	}
	Ans=min(Ans,sum[x]);
	if(son[x].size()==0) return;
	if(son[x].size()==1){
		gm[x].clear();
		gs[x].clear();
		gs[x].push_back(0LL);
		gm[x].push_back(0LL);
	}
	else{
		gm[x].clear();
		gs[x].clear();
		LL Y=0,Z=0;
		for(int i=0;i<son[x].size();++i){
			gs[x].push_back(Y);
			gm[x].push_back(Z);
			Y+=sum[son[x][i]];
			Z=max(Z,mx[son[x][i]]);
		}
		Y=0;Z=0;
		for(int i=son[x].size()-1;i>0;--i){
			Y+=sum[son[x][i]];
			Z=max(Z,mx[son[x][i]]);
			gs[x][i-1]+=Y;
			gm[x][i-1]=max(gm[x][i-1],Z);
		}
	}
	for(int i=0;i<son[x].size();++i){
		gs[x][i]+=sss;
		gm[x][i]=max(gm[x][i],mmm);
		if(gm[x][i]<h[x]){
			gs[x][i]+=h[x]-gm[x][i];
			gm[x][i]=h[x];
		}
		dfs2(son[x][i],gs[x][i],gm[x][i]);
	}
	return;
}

void MAIN(){
	int u,v;
	scanf("%d",&n);Ans=INF;
	for(int i=1;i<=n;++i) scanf("%lld",&h[i]);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	dfs1(1);
	for(int i=1;i<=n;++i){
		son[i].clear();
		for(int j=0;j<V[i].size();++j){
			if(V[i][j]!=fa[i]){
				son[i].push_back(V[i][j]);
			}
		}
	}
	Ans=sum[1];
	dfs2(1,0LL,0LL);
	LL www=0;
	for(int i=1;i<=n;++i) www=max(www,h[i]);
	Ans+=www;
	printf("%lld\n",Ans);
	return;
}
//Diaspora
//flex-block
//git config --global init.defaultBranch main
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}