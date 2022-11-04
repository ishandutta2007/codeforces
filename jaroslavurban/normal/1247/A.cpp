#include <stdio.h>
#include <stdlib.h>
#include <iostream>


int main(){
	int a, b;
	std::cin >> a >> b;
	if (a == b){
		printf("%d %d", a * 10, a * 10 + 1);
		return 0;
	}
	if (a + 1 == b){
		printf("%d %d", a * 10 + 9, b * 10);
		return 0;
	}
	if (a == 9 && b == 1){
		printf("9 10");
		return 0;
	}
	std::cout << -1;
	return 0;
}