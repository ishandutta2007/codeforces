#include <cstdio>
#include <algorithm>
void solve(){
	int a,b;
	scanf("%d%d",&a,&b);
	if((a&1)!=(b&1)){
		puts("-1");
		return;
	}
	if(a==b){
		if(a==0){
			puts("0");
			return;
		}
		puts("1");
		return;
	}
	puts("2");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}