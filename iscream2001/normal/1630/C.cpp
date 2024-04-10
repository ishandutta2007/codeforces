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
int R[N];


void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		R[i]=0;
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		R[a[i]]=i;
	}
	int w=0,ans=0,j;
	while(w<n){
		int i=w+1;
		if(i==R[a[i]]){
			++ans;
			w=i;
			continue;
		}
		int k=R[a[i]],r=0;
		j=1;
		while(k>r){
			r=k;++j;
			while(i<=r){
				k=max(k,R[a[i]]);
				++i;
			}
		}
		ans+=j;
		w=k;
	}
	printf("%d\n",n-ans);
	return;
}
//Diaspora
//flex-block
//git config --global init.defaultBranch main
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	init();
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}