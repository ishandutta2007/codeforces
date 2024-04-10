#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
int n;
int a[Maxn+5];
int num[2];
int lis[Maxn+5],lis_len;
void solve(){
	scanf("%d",&n);
	num[0]=num[1]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]&=1;
		num[a[i]]++;
	}
	if(std::abs(num[0]-num[1])>1){
		puts("-1");
		return;
	}
	if(num[0]==num[1]){
		lis_len=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				lis[++lis_len]=i;
			}
		}
		ll ans_1=0,ans_2=0;
		for(int i=1,j=1;i<=n;i+=2,j++){
			ans_1+=std::abs(i-lis[j]);
			ans_2+=std::abs(i+1-lis[j]);
		}
		printf("%lld\n",std::min(ans_1,ans_2));
	}
	else{
		if(num[0]>num[1]){
			std::swap(num[0],num[1]);
			for(int i=1;i<=n;i++){
				a[i]^=1;
			}
		}
		lis_len=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				lis[++lis_len]=i;
			}
		}
		ll ans=0;
		for(int i=1,j=1;i<=n;i+=2,j++){
			ans+=std::abs(i-lis[j]);
		}
		printf("%lld\n",ans);
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