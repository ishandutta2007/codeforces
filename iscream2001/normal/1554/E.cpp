#include<bits/stdc++.h>
using namespace std;
#define LL long long

const LL P=998244353;

const int N=2e5+10;

LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}

int n,m,K;

vector<int> V[100005]; 
LL ans[N];
LL F[N][2];
int sz[N];
int mu[N];
bool is_pri[N+10];
int pri[N],cntp=0;
void DP(int x,int fa){
	int y,z=0;
	sz[x]=1;
	LL re=1;
	F[x][0]=F[x][1]=0;
	for(int i=0;i<V[x].size();++i){
		y=V[x][i];
		if(y==fa) continue;
		DP(y,x);
		sz[x]+=sz[y];
		if((sz[y]-1)%K==0){
			++z;
			re=re*F[y][0];
		}
		else if((sz[y]-1)%K==K-1){
			re=re*F[y][1];
		}
		else re=0;
	}
	if((sz[x]-1)%K==0&&z%K==0){
		F[x][0]=re;
	}
	else if((sz[x]-1)%K==K-1&&z%K==K-1){
		F[x][1]=re;
	}
	return;
}
LL sol(int x){
	K=x;
	DP(1,0);
	return F[1][0];
}
void MAIN(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		V[i].clear();
		
	}
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	for(int i=1;i<=n;++i) ans[i]=0;
	ans[1]=qpow((LL)2,n-1);
	if(n!=2)ans[n-1]=sol(n-1);
	int x,y,z;
	x=n-1;
	for(int i=2;i<=sqrt(x);++i){
		if(x%i==0){
			ans[i]=sol(i);
			if(i*i!=x) ans[x/i]=sol(x/i);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+i,k=2;j<=n;j+=i,k++){
			ans[i]+=mu[k]*ans[j];
		}
	}
	for(int i=1;i<=n;++i){
		ans[i]=(ans[i]%P+P)%P;
		printf("%lld ",ans[i]);
	}
	puts("");
	return;
}

int main(){
	mu[1]=1;
	for(int i=2;i<=100000;++i){
        if(!is_pri[i]) {
            pri[++cntp]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=cntp&&pri[j]*i<=100000;++j){
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
	//init();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}