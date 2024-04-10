#include <cstdio>
#include <algorithm>
void solve(){
	int ans=0;
	int n;
	scanf("%d",&n);
	while(n){
		ans=std::max(ans,n%10);
		n/=10;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}