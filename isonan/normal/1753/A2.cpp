#include <bits/stdc++.h>

std::vector<std::pair<int,int> >ans;
int t,n,a[200001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		int sum=0;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			sum+=a[i];
		}
		if(sum&1){
			puts("-1");
			continue;
		}
		ans.clear();
		for(int i=1;i<=n;++i){
			if(a[i]==0)ans.push_back(std::make_pair(i,i));
			else{
				int j=i+1;
				while(!a[j])++j;
				if(a[i]!=a[j]){
					for(int k=i;k<=j;++k)ans.push_back(std::make_pair(k,k));
				}
				else{
					if(j==i+1)ans.push_back(std::make_pair(i,i+1));
					else{
						ans.push_back(std::make_pair(i,j-2));
						ans.push_back(std::make_pair(j-1,j));
					}
				}
				i=j;
			}
		}
		printf("%d\n",ans.size());
		for(auto v:ans)printf("%d %d\n",v.first,v.second);
	}
}