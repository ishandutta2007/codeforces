#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>ans;
int main(){
	int n; scanf("%d",&n);
	for (int i=1;i<=n*5+5;i++){
		int num=0;
		for (int j=5;j<=i;j*=5) num+=i/j;
		if (num==n) ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	printf("\n");
}