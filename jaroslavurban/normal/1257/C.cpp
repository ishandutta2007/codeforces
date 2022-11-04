#include <stdio.h>
#include <stdlib.h>
#include <iostream>


int main(){
	int t;
	std::cin >> t;
	int last_index[2*10*10*10*10*10 + 1];
	int min_length[2*10*10*10*10*10 + 1];
	for (int i = 0; i < t; i++){
		int n;
		std::cin >> n;
		for (int i = 0; i < n; i++)
			last_index[i] = min_length[i] = n;

		int num;
		for (int i = 0; i < n; i++){
			std::cin >> num;
			num--;
			if (last_index[num] == n)
				last_index[num] = i;
			else{
				if (i - last_index[num] < min_length[num])
					min_length[num] = i - last_index[num];
				last_index[num] = i;
			}
		}

		// printf("last index:\n");
		// for (int i = 0; i < n; i++){
		// 	printf("%d ", last_index[i]);
		// }
		// printf("\n min_length:\n");
		// for (int i = 0; i < n; i++){
		// 	printf("%d ", min_length[i]);
		// }
		// printf("\n");

		int min_len = n;
		for (int i = 0; i < n; i++){
			if (min_length[i] < min_len)
				min_len = min_length[i];
		}
		if (min_len == n)
			printf("-1\n");
		else{
			printf("%d\n", min_len + 1);
		}
	}
}