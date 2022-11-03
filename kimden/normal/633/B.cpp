#include <iostream>
#include <algorithm>
#include <cstdio>

int main()
{
	int m,l,i=1,j;
	int p=0,k=0;
	bool st=false;
	scanf("%d",&m);
	while(k<=m){
		j=i;
		p=0;
		if(i!=0){
			while(j%5==0){
				j/=5;
				p++;
			}
			k+=p;
		}
		if(k==m){
			if(!st){
				st=true;
				if(m!=0){
					printf("5\n");
				}else{
					printf("4\n");
				}
			}
			printf("%d ",i);
		}
		++i;
	}
	if(!st){
		printf("0");
	}
	return 0;
}