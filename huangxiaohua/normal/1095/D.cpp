#include<stdio.h>
 
int main(){
	static int a[200005][2],res=3,n,i,j=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	if(n==3){puts("1 2 3");return 0;}
	printf("3 ");
	while(j!=n)
	{
		if(a[res][1]==a[a[res][0]][1]){res=a[res][0];printf("%d ",res);j++;continue;}
		if(a[res][1]==a[a[res][0]][0]){res=a[res][0];printf("%d ",res);j++;continue;}
		if(a[res][0]==a[a[res][1]][1]){res=a[res][1];printf("%d ",res);j++;continue;}
		if(a[res][0]==a[a[res][1]][0]){res=a[res][1];printf("%d ",res);j++;continue;}
	}
	return 0;
}