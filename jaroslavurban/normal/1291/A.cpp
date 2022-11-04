#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

int main(){
	int t;
	std::cin >> t;
	size_t siz = 4000;
	char *lin = (char*) malloc(siz);
	for (int i = 0; i < t; i++){
		int n;
		scanf("%d\n", &n);
		int n_odd = 0;
		std::cin >> lin;
		for (int i = 0; i < n; i++){
			if ((lin[i] - '0') % 2)
				n_odd++;
			if (n_odd && n_odd % 2 == 0){
				for (int j = 0; j < i + 1; j++)
					printf("%c", lin[j]);
				break;
			}
		}
		if (!n_odd || n_odd % 2)
			printf("-1\n");
		else
			printf("\n");
	}
	free(lin);
}