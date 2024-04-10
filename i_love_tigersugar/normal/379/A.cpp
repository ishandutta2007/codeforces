#include<cstdio>
int main(void) {
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	int res=a;
	while (a>=b) {
		res++;
		a-=b-1;
	}
	printf("%d",res);
	return 0;
}