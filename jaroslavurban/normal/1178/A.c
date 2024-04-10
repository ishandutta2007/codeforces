#include <stdio.h>


int main(){
	int n, p, sum = 0;
	int parties[100] = {};

	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &p);
		sum += p;
		parties[i] = p;
	}

	int coalition[100] = {};
	int n_coalition_members = 1;
	int coalition_sum = parties[0];
	int majority = sum / 2 + 1;

	int index, min;

	for (int a = 0; a < n; a++){
		if (coalition_sum >= majority){
			printf("%d\n", n_coalition_members);
			for (int i = 0; i < n_coalition_members; i++){
				printf("%d", coalition[i] + 1);
				i + 1 == n_coalition_members ? printf("\n") : printf(" ");
			}
			return 0;
		}
		index = 0;
		min = parties[0] / 2;
		for (int i = 1; i < n; i++){
			// printf("%d %d %d\n", parties[i], min, sum);
			if (parties[i] <= min && parties[i] != 0){
				min = parties[i];
				index = i;
			}
		}
		if (index == 0){
			printf("0\n");
			return 0;
		}
		coalition_sum += parties[index];
		parties[index] = 0;
		coalition[a+1] = index;
		n_coalition_members += 1;
	}
}