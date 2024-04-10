#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int n,m;
vector<int>ans;
vector<vector<int>>a;
bool dfs(int step){
	if(step>2)return 0;
	for(int i=1;i<=n;++i){
		int num=0;
		for(int j=1;j<=m;++j){
			if(ans[j]!=a[i][j])num++;
		}
		if(num>4)return 0;
		if(num>2){
			for(int j=1;j<=m;++j){
				if(ans[j]!=a[i][j]){
					int t=ans[j];
					ans[j]=a[i][j];
					if(dfs(step+1))return 1;
					ans[j]=t;
				}
			}
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	a.resize(n+1);
	for(int i=1;i<=n;++i){
		a[i].resize(m+1);
		for(int j=1;j<=m;++j)scanf("%d",&a[i][j]);
	}
	ans=a[1];
	if(dfs(0)){
		printf("Yes\n");
		for(int i=1;i<=m;++i)printf("%d ",ans[i]);
		printf("\n");
	}
	else printf("no\n");
	return 0;
}  
/*                      
5 5
1 4 1 1 1
2 3 1 1 2
1 1 1 2 3
1 2 1 1 4
1 1 2 1 5

1 1 1 1 2
*/