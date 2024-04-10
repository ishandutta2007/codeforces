#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
int n;
bool np[Maxn+5];
ll ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	ll ans;
	scanf("%lld",&ans);
	return ans;
}
ll gcd(ll x,ll y){
	if(y==0){
		return x;
	}
	return gcd(y,x%y);
}
ll lcm(ll x,ll y){
	return 1ll*x*y/gcd(x,y);
}
std::mt19937 rnd(time(0));
void solve(){
	scanf("%d",&n);
	if(n<=100){
		static ll c[105][105];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				c[i][j]=c[j][i]=ask(i,j);
			}
		}
		if(n==3){
			for(int i=1;i<=200000;++i){
				int a[3]={i,i+1,i+2};
				do{
					if(lcm(a[0],a[1])==c[1][2]&&lcm(a[1],a[2])==c[2][3]&&lcm(a[0],a[2])==c[1][3]){
						printf("! %d %d %d\n",a[0],a[1],a[2]);
						fflush(stdout);
						return;
					}
				}while(std::next_permutation(a,a+3));	
			}
		}
		printf("! ");
		for(int i=1;i<=n;++i){
			ll x=0;
			for(int j=1;j<=n;++j){
				if(i==j){
					continue;
				}
				x=gcd(c[i][j],x);
			}
			printf("%lld ",x);
		}
		puts("");
		fflush(stdout);
		return;
	}
	int H=250,mx=-1,pos=-1;
	while(H--){
		ll g=0;
		int u=rnd()%n+1;
		for(int i=1;i<=20;i++){
			int v;
			do{
				v=rnd()%n+1;
			}while(u==v);
			g=gcd(g,ask(u,v));
		}
		if(!np[g]){
			if(g>mx){
				mx=g,pos=u;
			}
		}
	}
	static int a[Maxn+5];
	for(int i=1;i<=n;i++){
		a[i]=(i==pos?mx:ask(i,pos)/mx);
	}
	printf("! ");
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	puts("");
	fflush(stdout);
}
void init(int n){
	np[1]=1;
	for(int i=2;i<=n;++i){
		if(!np[i]){
			for(int j=i+i;j<=n;j+=i){
				np[j]=1;
			}
		}		
	}
}
int main(){
	init(200000);
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}