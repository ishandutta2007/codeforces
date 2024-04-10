#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,t,a[150],b[150],c[150],d,a1,d1;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);d=-1;d1=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&c[i]);
		}
		for(i=1;i<=n-1;i++){
			if(d!=a[i]){printf("%d ",a[i]);d=a[i];if(i==1){d1=d;}continue;}
			if(d!=b[i]){printf("%d ",b[i]);d=b[i];if(i==1){d1=d;}continue;}
			printf("%d ",c[i]);d=c[i];if(i==1){d1=d;}
		}
		if(d!=a[n]&&a[n]!=d1){printf("%d ",a[n]);}
		else{if(d!=b[n]&&b[n]!=d1){printf("%d ",b[n]);}
		else{printf("%d ",c[n]);
		}
		}
		puts("");
	}
}