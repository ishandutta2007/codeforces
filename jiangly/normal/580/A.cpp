#include<bits/stdc++.h>
const int N=1e5+5;
int n,ans;
int a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1,j=0;i<=n;++i){
		j=a[i]>=a[i-1]?j+1:1;
		ans=ans>j?ans:j;
	}
	printf("%d\n",ans);
	return 0;
}