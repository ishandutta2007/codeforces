#include<bits/stdc++.h>
using namespace std;
 
int n,p,i,sb[2020],no,rn,res[2020],j;
 
int main(){
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++){
		scanf("%d",&sb[i]);
	}
	sort(sb+1,sb+1+n);
	
	for(i=1;i<=sb[n];i++){
		no=0;
		for(j=n;j>=1;j--){
			//printf("x%d j%d\n",i,j);
			//printf("%d\n",i+n-(n-j)-sb[j]);
			if(i+n-1-(n-j)<sb[j]){no=1;break;}
			if(min((i+n-(n-j)-sb[j]),j)%p==0){no=1;break;}
		}
		if(no==0){rn++;res[i]=1;}
	}
	printf("%d\n",rn);
	for(i=1;i<=2000;i++){
		if(res[i]==1){printf("%d ",i);
		}
	}
}