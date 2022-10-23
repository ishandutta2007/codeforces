#include <bits/stdc++.h>

int t,n,k,a[100001],cnt[100001][2];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1,tem;i<=n;++i){
			scanf("%d",a+i);
			cnt[i][0]=cnt[i-1][0];
			cnt[i][1]=cnt[i-1][1];
			++cnt[i][a[i]];
		}
		int ans=n+1;
		for(int i=0;i<=n;++i){
			int x=std::max(cnt[n][0]-cnt[i][0],cnt[i][1]);
			if(ans>x)ans=x;
		}
		printf("%d\n",ans);
	}
}