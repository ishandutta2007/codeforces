#include<bits/stdc++.h>
const int N=5e2+5;
int n,k,ans;
int a[N];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;++i){
		if(a[i]+a[i-1]<k){
			ans+=k-a[i]-a[i-1];
			a[i]=k-a[i-1];
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i){
		printf("%d ",a[i]);
	}
	return 0;
}