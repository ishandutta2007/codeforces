#include <stdio.h>
#include <stdlib.h>
#include <iostream>


int main(){
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++){
		int n, x, l, r;
		std::cin >> n >> x >> l >> r;
		int min = l > r ? r : l;
		int max = l > r ? l : r;
		int distance = (max - min + x) < n - 1 ? (max - min + x) : n - 1;
		printf("%d\n", distance);		
	}
}