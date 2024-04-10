#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

int main(){
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++){
		int n;
		std::cin >> n;
		int sat = 1;
		long long mid1;
		for (int i = 0; i < n; i++){
			long long num;
			std::cin >> num;
			if (num < i && num < n - i - 1)
				sat = 0;
			if (n % 2 == 0 && i == n / 2 - 1)
				mid1 = num;
			if (n % 2 == 0 && i == n / 2 && mid1 == num && num == n - i - 1)
				sat = 0;
		}
		if (sat)
			printf("Yes\n");
		else
			printf("No\n");
	}
}