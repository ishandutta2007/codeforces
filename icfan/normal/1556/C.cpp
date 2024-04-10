#include <cstdio>
#include <algorithm>
template<typename Elem>
void write(Elem a){
	if(a<10){
		putchar(a+'0');
		return;
	}
	write(a/10);
	putchar(a%10+'0');
}
typedef long long ll;
const int Maxn=1000;
int n;
int c[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	__int128 ans=0;
	for(int i=1;i<=n;i+=2){
		ll sum=c[i],minn=c[i];
		for(int j=i+1;j<=n&&sum>=0;j++){
			if(j&1){
				sum+=c[j];
			}
			else{
				if(sum-c[i]<=c[j]){
					ll up=std::min(sum,1ll*c[j]);
					ll down=std::max(1ll,sum-minn);
					ans+=std::max(0ll,up-down+1);
				}
				sum-=c[j];
				minn=std::min(minn,sum);
			}
		}
	}
	write(ans);
	puts("");
	return 0;
}