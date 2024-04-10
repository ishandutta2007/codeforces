#include <cstdio>
#include <set>
#define int long long

int T,n,a[500001];
signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%lld",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%lld",&n);
		std::set<int>set;
		int k=1,b=0;
		bool isall=1;
		int mn=1;
		a[0]=0x7f7f7f7f;
		int L=-0x7f7f7f7f,R=0x7f7f7f7f;
		for(int i=1;i<=n;i++){
			scanf("%lld",a+i);
			k=-k,b=-b;
			b+=a[i];
			std::swap(L,R);
			L=a[i]-L,R=a[i]-R;
			L=std::max(L,1ll);
			R=std::min(R,a[i]-1ll);
			if(L>R)isall=0;
//			printf("%d %d\n",a[i],(a[i]>>1)*k-b*k);
			if(a[i]%2==0&&(set.count((a[i]>>1)*k-b*k)||(isall&&L<=(a[i]>>1)&&R>=(a[i]>>1)))){
				set.clear();
				set.insert((a[i]>>1)*k-b*k);
				isall=0;
//				printf("clear %d\n",a[i]);
			}
			else{
				if(a[i]%2==0)set.insert((a[i]>>1)*k-b*k);
				++mn;
//				printf("insert %d\n",a[i]);
			}
			for(;set.size();){
//				printf("%d %d\n",*set.begin(),a[i]);
				if(((*set.begin())*k+b)<1||((*set.begin())*k+b)>a[i]-1){
					set.erase(*set.begin());
				}
				else if(((*set.rbegin())*k+b)<1||((*set.rbegin())*k+b)>a[i]-1){
					set.erase(*set.rbegin());
				}
				else break;
			}
//			printf("%d %d %d\n",i,isall,set.size());
			if(set.empty()&&!isall){
				isall=1,++mn;
				L=1,R=a[i]-1;
			}
//			printf("%d\n",mn);
		}
		printf("%lld\n",mn);
	}
}