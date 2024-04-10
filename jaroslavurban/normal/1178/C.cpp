#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#define MOD 998244353

int main(){
	int a, b, result = 1;
	
	std::cin >> a >> b;

	for (int i = 0; i < a + b; i++)
		result = (result * 2) % MOD;
	
	std::cout << result;
    
    return 0;
}