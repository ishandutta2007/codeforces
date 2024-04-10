#include <bits/stdc++.h>

std::vector<std::pair<int,int> >ans;
int t,n,a[200001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
		}
		if(n&1){
			puts("-1");
			continue;
		}
		ans.clear();
		for(int i=1;i<=n;i+=2){
			if(a[i]==a[i+1]){
				ans.push_back(std::make_pair(i,i+1));
			}
			else{
				ans.push_back(std::make_pair(i,i));
				ans.push_back(std::make_pair(i+1,i+1));

			}
		}
		printf("%d\n",ans.size());
		for(auto v:ans)printf("%d %d\n",v.first,v.second);
	}
}