#include<bits/stdc++.h>
int n,a;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a);
		printf("%d ",a-(a%2==0));
	}
	return 0;
}