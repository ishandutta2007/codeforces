#include <cstdio>
void solve(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d %d %d\n",a+b+c,b+c,c);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}