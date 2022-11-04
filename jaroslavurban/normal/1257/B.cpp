#include <stdio.h>
#include <stdlib.h>
#include <iostream>


int main(){
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++){
		int a, b;
		std::cin >> a >> b;
		int prev_a = a;
		int possible = 1;
		while (a < b){
			// printf("%d\n", a);
			if (a % 2 && a > 1){
				prev_a = a;
				a--;
			}
			else if (a % 2 == 0 && a * 1.5 != prev_a){
				a *= 1.5;
			}
			else {
				possible = 0;
				break;
			}
		}
		if (possible)
			printf("YES\n");
		else
			printf("NO\n");
	}
}