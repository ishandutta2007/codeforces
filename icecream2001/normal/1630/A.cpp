#include<bits/stdc++.h>
#define double long double
#define LL long long
using namespace std;
const LL INF=1e18;
const double PI=acos(-1.0);
const LL M=998244353;
const int N=1e7+10;

LL qpow(LL x,LL y,LL mod=M){
	x%=mod;
	LL re=1;
	while(y){
		if(y&1) re=re*x%mod;
		y>>=1;x=x*x%mod;
	}
	return re;
}

inline char gc(){return getchar();}
inline int read(){
    int f=1,c; 
	while (c=gc(),c<48||c>57) if (c=='-') f=-1; 
	int x=c-'0';
    while(c=gc(),c>47&&c<58) x=x*10+c-'0'; 
	return f>0?x:-x;
}

bool is_pri[N+10];
int pri[N],cntp=0;
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
        }
    }
}

void init(){
	return;
}

int n,K;

void MAIN(){
	scanf("%d%d",&n,&K);
	if(n==4&&K==3){
		puts("-1");return;
	}
	int w=n-1;
	if(K!=n-1&&K!=0){
		printf("%d %d\n",w,K);
		printf("%d %d\n",0,w^K);
		for(int i=0;i<n;++i){
			if((w^i)<i) continue;
			if(i==0||i==w||i==K||i==(w^K)) continue;
			printf("%d %d\n",i,w^i);
		}
		return;
	}
	if(K==0){
		for(int i=0;i<n;++i){
			if((w^i)<i) continue;
			printf("%d %d\n",i,w^i);
		}
		return;
	}
	printf("%d %d\n",w,w-1);
	printf("%d %d\n",0,w^3);
	printf("%d %d\n",1,3);
	for(int i=0;i<n;++i){
		if((w^i)<i) continue;
		if(i==0||i==w||i==w-1||i==(w^3)||i==1||i==3) continue;
		printf("%d %d\n",i,w^i);
	}
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
	while(ttt--) MAIN();
	return 0;
}