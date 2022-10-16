#include<cstdio>
const char dig[][13]={"O-|-OOOO","O-|O-OOO","O-|OO-OO","O-|OOO-O","O-|OOOO-",
					"-O|-OOOO","-O|O-OOO","-O|OO-OO","-O|OOO-O","-O|OOOO-"};
int main(void) {
	int n;
	scanf("%d",&n);
	if (n==0) {
		printf("%s",dig[n]);
		return 0;
	}
	while (n>0) {
		printf("%s\n",dig[n%10]);
		n=n/10;
	}
	return 0;
}