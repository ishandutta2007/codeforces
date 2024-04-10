#include<bits/stdc++.h>
using namespace std;
 
int i,a[300500],b[300500],t,n,k,z,j,tmp,zz,res;
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&z);
		res=tmp=0;k++;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i]+b[i-1];
		}
		
		//for(i=1;i<=k;i++){printf("%d ",a[i]);}puts("");
		
		for(i=1;i<=k;i++){
			tmp+=a[i];zz=(k-i+1)/2;
			if(i==1){continue;}
			if(zz>z){zz=z;}
			res=max(res,b[k-zz*2]+(a[i]+a[i-1])*zz);
		}
		
		printf("%d\n",res);
	}
}