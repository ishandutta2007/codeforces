#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>


int main(){
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++){
		char a[200] = {};
		char b[200] = {};
		char c[200] = {};
		std::cin >> a >> b >> c;
		int pos = 1;
		for (int i = 0; a[i]; i++)
			pos *= (c[i] == a[i] || c[i] == b[i]);

		if (pos)
			printf("YES\n");
		else
			printf("NO\n");
	}
}