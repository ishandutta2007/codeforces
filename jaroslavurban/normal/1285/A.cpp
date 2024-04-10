#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>


#define ll long long int

int main(){
	int nc = 0;
	std::cin >> nc;

	int nl = 0;
	int nr = 0;

	for (int i = 0; i < nc + 1; i++){
		char c;
		scanf("%c",&c);
		if (c == 'R')
			nr++;
		if (c == 'L')
			nl++;
	}

	printf("%d\n", nl + nr + 1);
}