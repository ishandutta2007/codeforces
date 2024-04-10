#include <cstdio>
const int Maxn=100000;
int n,k;
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<(k<<1)-n;i++){
		printf("%d ",i);
	}
	for(int i=k;i>=(k<<1)-n;i--){
		printf("%d ",i);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}