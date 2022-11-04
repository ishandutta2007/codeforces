#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

int main(){
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++){
		char str[120] = {};
		std::cin >> str;
		int got1 = 0;
		int n_zeros = 0;
		int n_zeros_from_last_1 = 0;
		for (int j = 0; j < 120; j++){
			if (str[j] == 0)
				break;
			if (got1){
				if (str[j] == '0'){
					n_zeros_from_last_1++;
					n_zeros++;
				} else {
					n_zeros_from_last_1 = 0;
				}
			}
			if (str[j] == '1')
				got1 = 1;
		}
		printf("%d\n", n_zeros - n_zeros_from_last_1);
	}
}