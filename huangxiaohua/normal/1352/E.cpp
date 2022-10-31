#include<stdio.h>
 
int i,j,k,l,n,m,t,sb[8001],jb[8001],tmp,num;
 
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&m);num=0;
		for(j=1;j<=m;j++){
			scanf("%d",&sb[j]);
		}
		for(j=1;j<=m-1;j++){
			tmp=sb[j];
			for(k=j+1;k<=m;k++){
				tmp+=sb[k];
				if(tmp<=8000){
					jb[tmp]=i;
				}
				else{
					break;
				}
			}
		}
		for(j=1;j<=m;j++){
			num+=(jb[sb[j]]==i);
		}
		printf("%d\n",num);
	}
	return 0;
}