#include <stdio.h>
#include <stdlib.h>
#include <iostream>


#define min(a,b) \
  ({ __typeof__ (a) _a = (a); \
      __typeof__ (b) _b = (b); \
    _a > _b ? _b : _a; })

#define max(a,b) \
  ({ __typeof__ (a) _a = (a); \
      __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })


int main(){
	int k;

	std::cin >> k;

	for (int i = 0; i < k; i++){
		int n;
		int n_of_planks[1000] = {};
		std::cin >> n;
		for(int a = 0; a < n; a++){
			int num;
			scanf("%d", &num);
			n_of_planks[num-1]++;
		}

		int max = 0;
		int total = 0;
		for (int a = 999; a >= 0; a--){
			total += n_of_planks[a];
			int num1 = total;
			if (a + 1 < total)
				num1 = a + 1;
			if (num1 > max){
				max = num1;
			}
		}
		printf("%d\n", max);
	}
}