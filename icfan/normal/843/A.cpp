#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=100000;
int n;
std::pair<int,int> a[Maxn+5];
int p[Maxn+5];
bool vis[Maxn+5];
std::vector<int> ans[Maxn+5];
int len;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		p[i]=a[i].second;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		len++;
		for(int j=i;!vis[j];j=p[j]){
			vis[j]=1;
			ans[len].push_back(j);
		}
	}
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		printf("%d ",(int)ans[i].size());
		std::sort(ans[i].begin(),ans[i].end());
		for(int j:ans[i]){
			printf("%d ",j);
		}
		puts("");
	}
	return 0;
}