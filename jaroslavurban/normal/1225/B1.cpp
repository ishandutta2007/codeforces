#include <stdio.h>
#include <stdlib.h>
#include <iostream>


int main(){
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++){
		int ghetto_list[1000001] = {};
		int ghetto_list_indexes[1000001] = {};
		int list_start = 1;
		int shows_count = 0;
		int list_end = 1;
		int n, k, d;
		std::cin >> n >> k >> d;

		int min = d;

		for (int a = 0; a < n; a++){
			int show;
			std::cin >> show;

			if (ghetto_list_indexes[show] != 0){
				ghetto_list[ghetto_list_indexes[show]] = 0;
			}
			else{
				shows_count++;
			}
			ghetto_list_indexes[show] = list_end % 1000000 + 1;
			ghetto_list[list_end % 1000000 + 1] = show;
			list_end++;

			if (a >= d - 1){
				if (shows_count < min){
					min = shows_count;
				}
			}

			// printf("%d\n", shows_count);

			if (a >= d - 1){
				if (ghetto_list[list_start % 1000000 + 1] != 0){
					shows_count--;
					ghetto_list_indexes[ghetto_list[list_start % 1000000 + 1]] = 0;
					ghetto_list[list_start % 1000000 + 1] = 0;
				}
				list_start++;
			}

		}
		printf("%d\n", min);
	}
}