#include <cstdio>
#include <algorithm>

int t,n,u,v,a[101];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d%d",&n,&u,&v);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		int ans=0x7f7f7f7f,cnt=2;
		for(int i=2;i<=n;i++){
			cnt=std::min(cnt,(2-abs(a[i]-a[i-1])));
		}
		if(cnt==2)ans=std::min(ans,u+v);
		ans=std::min(ans,std::max(cnt,0)*v);
		for(int i=2;i<=n;i++){
			if(abs(a[i]-a[i-1])>1)break;
			if(a[i]!=a[i-1]||(i<n&&a[i]!=a[i+1]))ans=std::min(ans,u);
		}
		printf("%d\n",ans);
	}
}