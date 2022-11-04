#include <stdio.h>


int main(){
	long long after_v = 0;
	long long addition = 0;
	long long before_m = 0;
	long long wows = 0;
	char letter;
	while (1){
		scanf("%c", &letter);

		if (letter == 'v'){
			after_v++;
		}

		else if (letter == 'o'){
			wows += before_m * (after_v / 2 + (after_v - 1) / 2);
			addition += (after_v / 2 + (after_v - 1) / 2);
			before_m += addition;
			after_v = 0;
		}

		else {
			wows += before_m * (after_v / 2 + (after_v - 1) / 2);
			printf("%I64d\n", wows);
			return 0;
		}
	}
}