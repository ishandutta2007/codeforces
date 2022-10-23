#include <bits/stdc++.h>

std::vector<std::pair<int,int> >ans;
int t,n,a[500001],x,cnt[500001];
int main(){
	// scanf("%d",&t);
	t=1;
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&x);
		for(int i=1;i<=x;++i)cnt[i]=0;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			++cnt[a[i]];
		}
		bool ok=1;
		for(int i=1;i<x;++i){
			if(cnt[i]%(i+1)!=0){
				ok=0;
				break;
			}
			else cnt[i+1]+=cnt[i]/(i+1);
		}
		if(ok)puts("Yes");
		else puts("No");
	}
}