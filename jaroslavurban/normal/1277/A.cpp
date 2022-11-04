#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>


int main(){
	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++){
		long int n;
		std::cin >> n;
		long int n_of_zeros = -1;
		long int tmp_n = n;
		long int del = 1;
		while (tmp_n){
			tmp_n /= 10;
			del *= 10;
			n_of_zeros++;
		}
		del /= 10;

		long int is_smaller = 0;
		long int biggest = n / del;
		// printf("b %d\n", biggest);
		n -= biggest * del;
		del /= 10;
		while (del){
			if (n / del > biggest){
				break;
			}
			if (n / del < biggest){
				is_smaller = 1;
			}
			n -= (n / del) * del;
			del /= 10;
		}
		// printf("i %d\n", biggest);

		printf("%ld\n", n_of_zeros * 9 + biggest - is_smaller);
	}
}