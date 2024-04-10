#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=5e5+10;
bool is_pri[N+10];
int pri[N],cntp=0;

int mu[N+10]; 

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
void init(){
	init_pri();
}
int n,m;
int a[N],vis[N];
LL cnt[N];
vector<int> V[N];

void MAIN(){
	for(int i=1;i<=500000;++i){
		for(int j=i;j<=500000;j+=i){
			V[j].push_back(i);
		}
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	int x,y;
	LL ans=0;
	while(m--){
		scanf("%d",&x);
		for(int i=0;i<V[a[x]].size();++i){
			y=V[a[x]][i];
			if(!vis[x]){
				ans+=mu[y]*cnt[y];
				++cnt[y];
			}
			else{
				--cnt[y];
				ans-=mu[y]*cnt[y];
			}
		}
		vis[x]^=1;
		printf("%lld\n",ans);
	}
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;//scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}