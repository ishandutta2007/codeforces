#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a[100],n,ans;
void dfs(int x,int sum){
	if (x>n){
		if (sum%360==0)ans=1;
		return;
	}
	dfs(x+1,sum+a[x]);
	dfs(x+1,sum-a[x]);
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0);
	printf(ans?"YES\n":"NO\n");
}