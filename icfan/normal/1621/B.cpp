#include <cstdio>
#include <algorithm>
const int Maxn=100000;
const int Inf=0x7f7f7f7f;
int n;
void solve(){
	scanf("%d",&n);
	int min_l=Inf,max_r=0;
	int l_c=0,r_c=0;
	int min_all=0;
	for(int i=1;i<=n;i++){
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		if(l<min_l||(l==min_l&&c<l_c)){
			if(l<min_l){
				min_all=Inf;
			}
			min_l=l,l_c=c;
		}
		if(r>max_r||(r==max_r&&c<r_c)){
			if(r>max_r){
				min_all=Inf;
			}
			max_r=r,r_c=c;
		}
		if(l==min_l&&r==max_r){
			min_all=std::min(min_all,c);
		}
		printf("%d\n",std::min(l_c+r_c,min_all));
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