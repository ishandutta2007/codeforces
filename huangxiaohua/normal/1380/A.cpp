#include <bits/stdc++.h>
using namespace std;

int n,i,t,a[1050];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=2;i<=n-1;i++){
			if(a[i]>a[i-1]&&a[i]>a[i+1]){printf("YES\n%d %d %d\n",i-1,i,i+1);goto aaa;}
		}
		puts("NO");
		aaa:continue;
	}
}