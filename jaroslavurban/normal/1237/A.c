#include <stdio.h>
#include <math.h>


int main(){
	// int numbers[1400] = {};
	// int is_odd[1400] = {};
	// int n;
	// int temp, sum_of_even = 0;
	int temp, n;

	scanf("%d", &n);
	int sw = 0;
	int sw_n = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &temp);
		if (!(temp % 2)){
			temp = temp / 2;
			// printf("%d\n", temp / 2);
			// numbers[i] = temp;
			// is_odd[i] = 1;
		}
		else{
			if (temp > 0){
				if (sw){
					temp = temp / 2;
					sw = 0;
				}
				else{
					sw = 1;
					temp = temp / 2 + 1;
				}
			}
			else{
				if (sw_n){
					temp = temp / 2;
					sw_n = 0;
				}
				else{
					sw_n = 1;
					temp = temp / 2 - 1;
				}
				// num
			}

			// sum_of_even += temp / 2;
		}
		// numbers[i] = temp;
		// printf("%d\n", numbers[i]);
		printf("%d\n", temp);
	}

	// for (int i = 0; i < n; i++){
	// 	printf("%d\n", numbers[i]);
	// }

	// // int n_of_even_left = (n - n_of_odd) / 2;
	// int switchh = 0;
	// for (int i = 0; i < n; i++){
	// 	if (!is_odd[i]){
	// 		printf("%d\n", numbers[i] / 2);
	// 	}
	// 	else{
	// 		if ()
	// 		// if (sum_of_even > 0){
	// 		// 	printf("%d\n", sum_of_even);
	// 		// 	int new_n = numbers > 0 ? numbers[i] / 2 : numbers[i] / 2 - 1;
	// 		// 	sum_of_even -= new_n > 0 ? new_n : -new_n;
	// 		// 	printf("%d\n", new_n);
	// 		// }
	// 		// if (sum_of_even < 0){
	// 		// 	int new_n = numbers > 0 ? numbers[i] / 2 + 1 : numbers[i] / 2;
	// 		// 	sum_of_even -= new_n > 0 ? new_n : -new_n;
	// 		// 	printf("%d\n", new_n);
	// 		// }
	// 		// if (sum_of_even == 0){
	// 		// 	if (switchh){
	// 		// 		switchh = 0;
	// 		// 		printf("%d", numbers[i] / 2 + 1);
	// 		// 	}
	// 		// 	else{
	// 		// 		switchh = 1;
	// 		// 		printf("%d", numbers[i] / 2 - 1);
	// 		// 	}
	// 		// }
	// 	}
	// }

}