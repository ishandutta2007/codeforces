#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,a[200500],res,l,r,md,b[200500],c[200500];

int main(){
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
    	scanf("%d",&a[i]);
	}
	l=1;r=n;
	while(l<=r){
		md=(l+r)/2;j=0;
		for(i=1;i<=n;i++){
			if(a[i]>=md){b[i]=b[i-1]+1;}
			else{b[i]=b[i-1]-1;}
			c[i]=min(c[i-1],b[i]);
		}
		for(i=k;i<=n;i++){
			if(b[i]>c[i-k]){j=1;break;}
		}
		if(j){l=md+1;res=max(res,md);}
		else{r=md-1;}
	}
	printf("%d",res);
}