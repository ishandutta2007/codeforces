#include <cstdio>
#include <cmath>
#define int long long


int map[1001][1001],a[1001];
int n;
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			scanf("%I64d",&map[i][j]);
	}
	for(int i=1;i<=n;i++){
		int t1=1,t2=2;
		if(t1==i)t1=3;
		if(t2==i)t2=3;
		printf("%I64d ",(long long)sqrt((map[i][t1]*map[i][t2])/map[t1][t2]));
	}
}