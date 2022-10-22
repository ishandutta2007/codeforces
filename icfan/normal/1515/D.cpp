#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n,l,r;
int num_l[Maxn+5],num_r[Maxn+5];
void solve(){
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1;i<=n;i++){
		num_l[i]=num_r[i]=0;
	}
	for(int i=1;i<=l;i++){
		int c;
		scanf("%d",&c);
		num_l[c]++;
	}
	for(int i=1;i<=r;i++){
		int c;
		scanf("%d",&c);
		num_r[c]++;
	}
	int ans=(l>r?((l-r)>>1):((r-l)>>1));
	int num=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=std::abs(num_l[i]-num_r[i]);
		if((num_l[i]>num_r[i])==(l>r)){
			num+=(std::abs(num_l[i]-num_r[i])>>1);
		}
	}
	ans=(ans+std::max((sum>>1)-std::min(num,ans),0));
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