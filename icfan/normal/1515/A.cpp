#include <cstdio>
#include <algorithm>
const int Maxn=100;
const int Maxv=10000;
int a[Maxn+5];
int n,x;
void solve(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a+1,a+1+n);
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum==x){
			if(i==n){
				puts("NO");
				return;
			}
			if(i==1){
				std::swap(a[1],a[2]);
				break;
			}
			std::swap(a[i],a[i-1]);
			std::swap(a[i],a[i+1]);
			break;
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
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