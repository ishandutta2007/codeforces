#include <stdio.h>
#include <stdlib.h>
#include <iostream>


int main(){
	int k;
	std::cin >> k;

	for (int a = 0; a < k; a++){
		int len;
		std::cin >> len;
		char s[len + 1];
		char t[len + 1];

		char nl;
		scanf("%c", &nl);
		for (int i = 0; i < len; i++){
			scanf("%c", &s[i]);
			// printf("%d %c\n", i, s[i]);
		}
		scanf("%c", &nl);
		// printf("\n");
		for (int i = 0; i < len; i++){
			scanf("%c", &t[i]);
			// printf("%d %c\n", i, t[i]);
		}
		// printf("\n");

		char upper_needs;
		char upper_has;
		int found_diff = 0;
		int swapped = 0;
		int can_transform = 1;

		for (int i = 0; i < len; i++){
			// printf("%d %c %c\n", i, s[i], t[i]);

			if (s[i] == t[i])
				continue;

			if (!found_diff){
				found_diff = 1;
				upper_has = s[i];
				upper_needs = t[i];
				can_transform = 0;
			}
			else{
				if (upper_needs == t[i] && upper_has == s[i] && !swapped){
					swapped = 1;
					can_transform = 1;
				}
				else{
					can_transform = 0;
					break;
				}
			}
		}

		if (can_transform)
			printf("Yes\n");
		else
			printf("No\n");

	}
}