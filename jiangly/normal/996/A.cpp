#include<bits/stdc++.h>
const int a[]={100,20,10,5,1};
int n,ans;
int main(){
	scanf("%d",&n);
	for(int i=0;i<5;++i){
		ans+=n/a[i];
		n%=a[i];
	}
	printf("%d\n",ans);
	return 0;
}