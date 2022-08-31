#include<bits/stdc++.h>
int n,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		ans+=n%i==0;
	}
	printf("%d\n",ans);
	return 0;
}