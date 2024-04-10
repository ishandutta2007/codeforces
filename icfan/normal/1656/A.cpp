#include <cstdio>
#include <algorithm>
const int Maxn=100000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
void solve(){
	std::pair<int,int> ans_l=std::make_pair(Inf,0),ans_r=std::make_pair(-Inf,0);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans_l=std::min(ans_l,std::make_pair(a[i],i));
		ans_r=std::max(ans_r,std::make_pair(a[i],i));
	}
	printf("%d %d\n",ans_l.second,ans_r.second);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}