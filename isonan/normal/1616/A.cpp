#include <cstdio>

int t,n;
int cnt[101];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=0;i<=100;++i)cnt[i]=0;
		int ans=0;
		for(int i=1,a;i<=n;++i){
			scanf("%d",&a);
			if(a<0)a=-a;
			++cnt[a];
			if(a==0){
				if(cnt[a]==1)++ans;
			}
			else if(cnt[a]<=2)++ans;
		}
		printf("%d\n",ans);
	}
}