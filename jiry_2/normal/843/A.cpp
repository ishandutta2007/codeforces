#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int A[110000],n,pd[110000],len,a[110000];
vector<int>ans[110000];
int compare(int k1,int k2){
	return A[k1]<A[k2];
}
void dfs(int k){
	ans[len].push_back(k);
	pd[k]=1; if (pd[a[k]]==0) dfs(a[k]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),a[i]=i;
	sort(a+1,a+n+1,compare);
	for (int i=1;i<=n;i++)
		if (pd[i]==0){
			len++; dfs(i);
		}
	printf("%d\n",len);
	for (int i=1;i<=len;i++){
		sort(ans[i].begin(),ans[i].end());
		printf("%d ",(int)ans[i].size());
		for (int j=0;j<ans[i].size();j++) printf("%d ",ans[i][j]);
		putchar('\n');
	}
}