#include <cstdio>
#include <vector>
#include <algorithm>

int n,m,a[101][101];
std::vector<int>ans,tem;
struct point{int ord,v;}num[101];
bool cmp(point a,point b){return a.v>b.v;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j][i]);
	ans.resize(n+1);
	for(int i=1;i<n;i++){
		tem.clear();
		for(int j=1;j<=m;j++)num[j]=(point){j,a[i][j]-a[n][j]};
		std::sort(num+1,num+m+1,cmp);
		int sum=0;
		for(int j=1;j<=m;j++){
			sum+=num[j].v;
			if(sum<0){
				for(int k=j;k<=m;k++)tem.push_back(num[k].ord);
				break;
			}
		}
		if(tem.size()<ans.size())ans=tem;
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
}