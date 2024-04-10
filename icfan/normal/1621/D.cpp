#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=500;
int c[Maxn+5][Maxn+5];
int n;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++){
		for(int j=1;j<=2*n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	ll ans=0;
	for(int i=n+1;i<=2*n;i++){
		for(int j=n+1;j<=2*n;j++){
			ans+=c[i][j];
		}
	}
	printf("%lld\n",ans+std::min(std::min(std::min(c[n][n+1],c[n+1][n]),std::min(c[2*n][n],c[n][2*n])),std::min(std::min(c[2*n][1],c[n+1][1]),std::min(c[1][2*n],c[1][n+1]))));
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}