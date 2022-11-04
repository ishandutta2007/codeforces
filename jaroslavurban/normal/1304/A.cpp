#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>


int main(){
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++){
		long long a, b, x, y;
		std::cin >> x >> y >> a >> b;
		y -= x;
		if (y % (a + b) == 0)
			std::cout << y / (a + b) << '\n';
		else
			std::cout << -1 << '\n';
	}
}