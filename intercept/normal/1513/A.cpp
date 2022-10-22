#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,k;
	scanf("%d%d",&n,&k);
	if((n-1)/2<k){printf("-1\n");return;}
	int l=1,r=n;
	for(int i=1;i<=n;++i){
		if((i&1)||!k)printf("%d ",l++);
		else printf("%d ",r--),k--;
	}
	printf("\n");
}
int main(){
	int T;
	scanf("%d\n",&T);
	while(T--)work();
	return 0;
}