#include <bits/stdc++.h>
using namespace std;
 
long long i,a[50]={1,1},b[50],res,n,p,t,m;

int main(){
	for(i=2;a[i-1]<=1000000000;i++){
		a[i]=a[i-1]*2;
	}
	scanf("%d",&t);
	while(t--){
		res=1;
		scanf("%d%d",&n,&p);
		memset(b,0,sizeof(b));
		m=n;
		for(i=1;n>0;i++){
			if(n>=a[i]){b[i]=a[i];n-=b[i];}
			else{b[i]=n;n=0;}
		}
		for(i=1;a[i-1]<=m;i++){
			res*=(b[i]+1);
			res%=p;
		}
		res=(res-1+p)%p;
		printf("%lld\n",res);
	}
	
}