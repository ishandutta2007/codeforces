#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,ans;
int main(){
	scanf("%d%d",&n,&m);
	int ans=n+1;
	for (;m;m--){
		int k1,k2; scanf("%d%d",&k1,&k2); ans=min(ans,k2-k1+1);
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) printf("%d ",i%ans); printf("\n");
	return 0;
}