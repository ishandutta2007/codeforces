#include <cstdio>
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	if((n+1)/2<k){
		puts("-1");
		return;
	}
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(num<k&&i==j&&(i&1)){
				putchar('R');
				num++;
			}
			else{
				putchar('.');
			}
		}
		putchar('\n');
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}