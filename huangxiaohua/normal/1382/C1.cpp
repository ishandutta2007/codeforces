#include<bits/stdc++.h>
using namespace std;

int n,i,j,m,t,res[200500],k,a[105000],b[105000],c[100500],tt;

int main(){
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);k=t=0;
		for(i=1;i<=n;i++){
			scanf("%1d",&a[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%1d",&b[i]);
		}
		for(i=1,j=n;i<=n;i++,j--){
			c[i]=a[j]^1;
		}
		for(i=n,j=1;i>=1;i--,j++){
			if(t%2==0){
				if(a[(j+1)/2]!=b[i]){k++;t++;res[j]=1;continue;}
				if(a[(j+1)/2]==b[i]){k+=2;t++;res[j]=2;continue;}
			}
			if(t%2==1){
				if(c[(j+1)/2]!=b[i]){k++;t++;res[j]=1;continue;}
				if(c[(j+1)/2]==b[i]){k+=2;t++;res[j]=2;continue;}
			}
		}
		printf("%d ",k);
		for(i=1,j=n;i<=n;i++,j--){
			if(res[i]==1){printf("%d ",j);}
			if(res[i]==2){printf("1 %d ",j);}
		}puts("");
	}
}