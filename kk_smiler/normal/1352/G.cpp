#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k,ans[1010];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n<=3){
			puts("-1");
			continue;
		}
		for(int i=1;i<=((n+1)>>1);i++){
			if(i%2==1) ans[((n+1)>>1)-(i-1)/2]=i*2-1,ans[n-(i-1)/2]=i*2;
			if(i%2==0) ans[i/2]=i*2-1,ans[((n+1)>>1)+i/2]=i*2;
		}
		for(int i=1;i<=n;i++) printf("%d ",ans[i]>n?n-1:ans[i]);
		printf("\n");
	}
}