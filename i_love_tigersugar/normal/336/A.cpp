#include<cstdio>
int x,y;
int main(void) {
	scanf("%d",&x);
	scanf("%d",&y);
	if ((x>0 && y>0) || (x<0 && y<0)) {
		if (x+y>0) printf("0 %d %d 0",x+y,x+y);
		else printf("%d 0 0 %d",x+y,x+y);
	}	
	else {
		if (x-y>0) printf("0 %d %d 0",y-x,x-y);
		else printf("%d 0 0 %d",x-y,y-x);
	}
}