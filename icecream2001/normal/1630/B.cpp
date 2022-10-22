#include<bits/stdc++.h>
#define double long double
#define LL long long
using namespace std;
const LL INF=1e18;
const double PI=acos(-1.0);
const LL M=998244353;
const int N=2e5+10;

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

int a[N];
int b[N];


void MAIN(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;++i) b[i]=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	int L=1,R=n,now=0;
	for(int i=1,j=1;i<=n;++i){
		now+=b[i];
		while(now-b[j]-(n-(now-b[j]))>=K&&j<=i){
			now-=b[j];
			++j;
		}
		if(now-(n-now)>=K&&i-j<R-L){
			R=i;L=j;
		}
	}
	printf("%d %d\n",L,R);
	now=0;
	int used=0;
	for(int i=1;i<K;++i){
		printf("%d ",used+1);now=0;
		while(now!=1){
			used++;
			if(a[used]>=L&&a[used]<=R){
				++now;
			}
			else {
				--now;
			}
		}
		printf("%d\n",used);
	}
	printf("%d %d\n",used+1,n);
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