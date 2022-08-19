#include<bits/stdc++.h>
int n,sum,Max;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int a;
		scanf("%d",&a);
		sum+=a;
		Max=std::max(Max,a);
	}
	printf("%d\n",Max*n-sum);
	return 0;
}