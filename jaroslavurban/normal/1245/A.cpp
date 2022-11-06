#include <stdio.h>


int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 


int main(){
	int a, b, t;

	scanf("%d", &t);

	// printf("%d\n", gcd(a, b));

	for (int i = 0; i < t; i++){
		scanf("%d%d", &a, &b);
		if (gcd(a,b) == 1){
			printf("Finite\n");
		}
		else{
			printf("Infinite\n");
		}
	}
}