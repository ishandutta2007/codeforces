#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n,k;
int a[Maxn+5];
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int pos=std::lower_bound(a+1,a+1+n,a[i]+k)-a;
		if(pos<=n&&a[pos]==a[i]+k){
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}