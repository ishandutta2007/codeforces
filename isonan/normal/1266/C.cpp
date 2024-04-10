#include <cstdio>

int r,c;
int gcd(int a,int b){
	return (!b)?a:gcd(b,a%b);
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
}
int main(){
	scanf("%d%d",&r,&c);
	if(r==1&&c==1){
		puts("0");
		return 0;
	}
	for(int i=1;i<=r;i++,putchar('\n'))
		for(int j=1;j<=c;j++)
			printf("%d ",(r<=c)?lcm(i,r+j):lcm(c+i,j));
}