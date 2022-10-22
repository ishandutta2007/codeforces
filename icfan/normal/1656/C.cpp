#include <cstdio>
#include <algorithm>
const int Maxn=100000;
int n;
int a[Maxn+5];
void solve(){
	bool flag_1=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1){
			flag_1=1;
		}
	}
	if(!flag_1){
		puts("YES");
		return;
	}
	std::sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		if(a[i]+1==a[i+1]){
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}