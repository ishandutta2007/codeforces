#include <cstdio>
#include <algorithm>

int t,n;
int a[200001],pre[200001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		for(int i=1;i<=n;++i)pre[i]=(a[i]==a[i-1])?pre[i-1]:i;
		int Ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1,s=i;;++j){
				Ans=std::max(Ans,j+i-pre[i]);
				int l=s+1,r=n,mid,ans=n+1;
				while(l<=r){
					mid=(l+r)>>1;
					if(a[mid]-a[s]>=a[s]-a[i]&&a[mid]>a[s])ans=mid,r=mid-1;
					else l=mid+1;
				}
				if(ans==n+1)break;
				s=ans;
			}
		}
		printf("%d\n",n-Ans);
	}
}