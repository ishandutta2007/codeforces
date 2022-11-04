#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>


#define ll long long unsigned int


int main(){
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++){
		ll n;
		std::cin >> n;
		if (n < 15 || (n - 7) % 14 <= 7)
			printf("NO\n");
		else
			printf("YES\n");
	}
}