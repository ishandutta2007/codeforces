#include <cmath>
#include <cstdio>
void solve(){
	int n;
	scanf("%d",&n);
	if(n&1){
		puts("NO");
		return;
	}
	int t=(n>>1);
	int val=ceil(sqrt(t*1.0));
	if(val*val==t){
		puts("YES");
		return;
	}
	if(n%4==0){
		t=n>>2;
		val=ceil(sqrt(t*1.0));
		if(val*val==t){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	else{
		puts("NO");
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