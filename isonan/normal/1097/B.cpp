#include <cstdio>
#include <cstdlib>

int n,a[20];
void dfs(int x,int sum){
	if(x>n){
		if(sum%360==0){
			puts("YES");
			exit(0);
		}
		return;
	}
	dfs(x+1,sum+a[x]);
	dfs(x+1,sum-a[x]+360);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	dfs(1,0);
	puts("NO");
}