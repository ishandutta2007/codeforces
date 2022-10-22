#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define ull unsigned long long
const int N=1e5+10;
const LL INF=1e18;
const LL P=1073741824LL;

bool is_pri[N];
int pri[N],cntp=0;
int mu[N];
void init_pri(){
	mu[1]=1;
    for(int i=2;i<N;++i){
        if(!is_pri[i]) {
            pri[++cntp]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=cntp&&pri[j]*i<N;++j){
            is_pri[pri[j]*i]=1;
            if(i%pri[j]==0) {
				break;
            }
            else{
            	mu[pri[j]*i]=-mu[i];
			}
        }
    }
    return;
}

void init(){
	init_pri();
	return;
}
LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}

int A,B,C,M;
LL a[N],b[N],c[N];
LL ans;

void getarr(int x,LL *y){
	for(int i=1;i<=M;++i){
		y[i]=0;
		for(int j=i;j<=M;j+=i){
			y[i]+=x/j;
		}
	}
	return;
}

int d[N];

struct edge{
	int u,v,w;
};

vector<edge> E;

struct node{
	int u,w;
};

vector<node> V[N];

int vis[N];

void MAIN(){
	int u,v,w,x,y;
	ans=0;
	scanf("%d%d%d",&A,&B,&C);M=max(A,max(B,C));
	getarr(A,a);getarr(B,b);getarr(C,c);
	for(int i=1;i<=M;++i) if(mu[i]) ans+=mu[i]*a[i]*b[i]*c[i];
	//cout<<ans<<endl;
	for(int i=1;i<=M;++i) {
		d[i]=0;V[i].clear();
	}
	E.clear();
	for(int g=1;g<=M;++g) {
		x=M/g;
		for(int i=1;i<=x;++i){
			if(mu[i*g]){
				y=x/i;
				for(int j=i+1;j<=y;++j){
					if(mu[j*g]&&__gcd(i,j)==1){
						u=i*g;v=j*g;w=u*j;
						ans+=mu[u]*mu[u]*mu[v]*(a[u]*b[w]*c[w]+a[w]*b[u]*c[w]+a[w]*b[w]*c[u]);
						ans+=mu[u]*mu[v]*mu[v]*(a[v]*b[w]*c[w]+a[w]*b[v]*c[w]+a[w]*b[w]*c[v]);
						++d[u];++d[v];E.push_back((edge){u,v,w});
					}
				}
			}
		}
	}
	//cout<<ans<<endl;
	for(int i=0;i<E.size();++i){
		if(d[E[i].u]<d[E[i].v]||(d[E[i].u]==d[E[i].v]&&E[i].u<E[i].v)) 
			V[E[i].v].push_back((node){E[i].u,E[i].w});
		else
			V[E[i].u].push_back((node){E[i].v,E[i].w});
	}
	for(int i=1;i<=M;++i){
		for(int j=0;j<V[i].size();++j){
			vis[V[i][j].u]=V[i][j].w;
		}
		for(int j=0;j<V[i].size();++j){
			u=V[i][j].u;
			for(int k=0;k<V[u].size();++k){
				v=V[u][k].u;
				if(vis[v]){
					ans+=mu[i]*mu[u]*mu[v]*(
						 a[V[i][j].w]*b[vis[v]]*c[V[u][k].w]//iuv
					    +a[vis[v]]*b[V[i][j].w]*c[V[u][k].w]//ivu
						+a[V[i][j].w]*b[V[u][k].w]*c[vis[v]]//uiv
						+a[V[u][k].w]*b[V[i][j].w]*c[vis[v]]//uvi
						+a[vis[v]]*b[V[u][k].w]*c[V[i][j].w]//viu
						+a[V[u][k].w]*b[vis[v]]*c[V[i][j].w]//vui
					);
				}
			}
		}
		for(int j=0;j<V[i].size();++j){
			vis[V[i][j].u]=0;
		}
	}
	ans=(ans%P+P)%P;
	printf("%lld\n",ans);
	return;
}
int main(){
	init();
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}
/*
5
10 10 10
100 100 100
1000 1000 1000
10000 10000 10000
100000 100000 100000
*/
 /*
11536
51103588
165949340
19234764
176764584
 */