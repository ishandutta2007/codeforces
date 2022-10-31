#include<bits/stdc++.h>
using namespace std;

int k,n,i,t,a[200500];
long long res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);res=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=n;i>=2;i--){
			if(a[i]<a[i-1]){res+=a[i-1]-a[i];}
		}printf("%lld\n",res);
	}
	
}