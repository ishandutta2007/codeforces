#include <cstdio>
#include <algorithm>
const int Maxn=100000;
int n;
int a[Maxn+5],b[Maxn+5];
int sum_a[Maxn+5],sum_b[Maxn+5];
bool check(int x){
	int tmp_n=x+n;
	int del_v=(tmp_n>>2);
	del_v=std::min(del_v,n);
	int s_a=x*100+sum_a[n]-sum_a[del_v],s_b=(tmp_n-del_v>=n?sum_b[n]:sum_b[n]-sum_b[del_v-x]);
	if(s_a>=s_b){
		return 1;
	}
	return 0;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	std::sort(a+1,a+1+n);
	std::sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		sum_a[i]=sum_a[i-1]+a[i];
		sum_b[i]=sum_b[i-1]+b[i];
	}
	int left=0,right=(n<<2);
	while(left<right){
		int mid=(left+right)>>1;
		if(check(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	printf("%d\n",left);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}