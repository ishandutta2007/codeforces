#include <cstdio>
#include <algorithm>

int t;
long long p,q;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%lld%lld",&p,&q);
		long long ans=0,o=q;
		for(int i=2;i*i<=q;i++)
			if(q%i==0){
				while(q%i==0)q/=i;
				long long r=p;
				while(r%o==0)r/=i;
				ans=std::max(ans,r);
			}
		if(q>1){
			long long r=p;
			while(r%o==0)r/=q;
			ans=std::max(ans,r);
		}
		printf("%lld\n",ans);
	}
}