#include <cstdio>
#include <vector>

std::vector<int>ans;
int t,n;
long long w,a[200001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%lld",&n,&w);
		for(int i=1;i<=n;i++)scanf("%lld",a+i);
		ans.clear();
		for(int i=1;i<=n;i++)
			if(a[i]>=((w+1ll)>>1ll)&&a[i]<=w){
				ans.push_back(i);
				break;
			}
		if(ans.size()){
			printf("%d\n",ans.size());
			printf("%d\n",ans[0]);
		}
		else{
			long long sum=0;
			for(int i=1;i<=n;i++)
				if(a[i]<((w+1ll)>>1ll)){
					sum+=a[i];
					ans.push_back(i);
					if(sum>=((w+1ll)>>1ll)){
						break;
					}
				}
			if(sum>=((w+1ll)>>1ll)){
				printf("%d\n",ans.size());
				for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);putchar('\n');
			}
			else{
				puts("-1");
			}
		}
	}
}