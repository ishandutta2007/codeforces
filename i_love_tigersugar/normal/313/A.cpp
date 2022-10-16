#include<stdio.h>
int x;
int main(void) {
	scanf("%d",&x);
	if (x>0) {
		printf("%d",x);
		return 0;
	}
	x=-x;	
	if ((x/100)*10+x%10<x/10) printf("%d",-((x/100)*10+x%10));
	else printf("%d",-x/10);
	return 0;
}