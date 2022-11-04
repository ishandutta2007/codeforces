#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>


#define ll long long int


int main(){
	int t;
	std::cin >> t;
	char c;
	scanf("%c", &c);
	for (int i = 0; i < t; i++){
		char digit;
		int even = 0;
		int n_zero = 0;
		int sum = 0;
		while (1){
			if (scanf("%c", &digit) == EOF || digit == '\n'){
				break;				
			}
			sum += (int)digit;
			if (digit == '0')
				n_zero += 1;
			if ((int)digit % 2 == 0 && digit != '0'){
				even = 1;
			}
		}
		if (sum % 3 == 0 && n_zero && (even || n_zero > 1))
			printf("red\n");
		else
			printf("cyan\n");
	}
}