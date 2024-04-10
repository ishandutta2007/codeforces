#include<bits/stdc++.h>
using namespace std;

long long k,n,i,t,res1[200500],res2[200500],a[200500],mx,mx2;

int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&k);mx=mx2=-1111111111;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			mx=max(a[i],mx);
		}
		for(i=1;i<=n;i++){
			res1[i]=mx-a[i];
			mx2=max(res1[i],mx2);
		}
		for(i=1;i<=n;i++){
			res2[i]=mx2-res1[i];
		}
		if(k%2==1){
			for(i=1;i<=n;i++){
				printf("%d ",res1[i]);
			}puts("");
		}
		else{
			for(i=1;i<=n;i++){
				printf("%d ",res2[i]);
			}puts("");
		}
	}
}