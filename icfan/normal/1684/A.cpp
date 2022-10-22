#include <cstdio>
#include <algorithm>
int n;
int lis[15];
int len;
void solve(){
	scanf("%d",&n);
	len=0;
	while(n>0){
		lis[++len]=n%10;
		n/=10;
	}
	if(len==2){
		printf("%d\n",lis[1]);
		return;
	}
	int ans=10;
	for(int i=1;i<=len;i++){
		ans=std::min(ans,lis[i]);
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