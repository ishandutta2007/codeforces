#include <cstdio>
typedef long long ll;
const int Maxn=200000;
int n;
ll a[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	while(n>0&&a[n]==0){
		n--;
	}
	if(n==0){
		puts("Yes");
		return;
	}
	a[n+1]=0;
	for(int i=n;i>1;i--){
		a[i]+=a[i+1];
		if(a[i]>=0){
			puts("No");
			return;
		}
	}
	a[1]+=a[2];
	if(a[1]!=0){
		puts("No");
		return;
	}
	puts("Yes");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}