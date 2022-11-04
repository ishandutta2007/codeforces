#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>


int place(char *layout, int letters[26][3], int i){
	int num = layout[i];
	int n1 = letters[num][0];
	int n2 = letters[num][1];
	if (n1 != -1 && letters[n1][2] && layout[i-1] != n1 && layout[i+1] != n1)
		return 0;
	if (n2 != -1 && letters[n2][2] && layout[i-1] != n2 && layout[i+1] != n2)
		return 0;
	int out1 = 1;
	int out2 = 1;
	if (n1 != -1 && !letters[n1][2]){
		if (layout[i-1] == -1){
			layout[i-1] = n1;
			letters[n1][2] = 1;
			out1 = place(layout, letters, i-1);
		} else if (layout[i+1] == -1){
			layout[i+1] = n1;
			letters[n1][2] = 1;
			out1 = place(layout, letters, i+1);
		} else{
			return 0;
		}
	}
	if (n2 != -1 && !letters[n2][2]){
		if (layout[i-1] == -1){
			layout[i-1] = n2;
			letters[n2][2] = 1;
			out2 = place(layout, letters, i-1);
		} else if (layout[i+1] == -1){
			layout[i+1] = n2;
			letters[n2][2] = 1;
			out2 = place(layout, letters, i+1);
		} else{
			return 0;
		}
	}
	return out1 * out2;
}

int main(){
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++){
		char str[250] = {};
		std::cin >> str;
		int letters[26][3];
		for (int i = 0; i < 26; i++){
			letters[i][0] = -1;
			letters[i][1] = -1;
			letters[i][2] = 0;
		}
		char can = 1;
		for (int i = 1; str[i]; i++){
			int l1 = str[i-1] - 'a';
			int l2 = str[i] - 'a';
			if (letters[l1][0] == l2 ||
				letters[l1][1] == l2)
				continue;
			if (letters[l1][0] == -1){
				if (letters[l2][0] == -1){
					letters[l1][0] = l2;
					letters[l2][0] = l1;
				} else if (letters[l2][1] == -1){
					letters[l1][0] = l2;
					letters[l2][1] = l1;
				} else{
					can = 0;
					break;
				}
			} else if (letters[l1][1] == -1){
				if (letters[l2][0] == -1){
					letters[l1][1] = l2;
					letters[l2][0] = l1;
				} else if (letters[l2][1] == -1){
					letters[l1][1] = l2;
					letters[l2][1] = l1;
				} else{
					can = 0;
					break;
				}
			} else{
				can = 0;
				break;
			}
		}
		if (!can){
			printf("NO\n");
			continue;
		}
		int startInd = 0;
		char layout[80];
		for (int i = 0; i < 80; i++)
			layout[i] = -1;

		int myind = -1;
		for (int i = 0; i < 26; i++)
			if (letters[i][0] == -1 && letters[i][1] == -1)
				layout[startInd++] = i;
			else
				myind = i;

		layout[40] = myind;
		if (myind != -1){
			letters[myind][2] = 1;
			can = place(layout, letters, 40);
		}
		if (!can){
			printf("NO\n");
			continue;
		} else {
			printf("YES\n");
			for(int i = 0; i < 80; i++){
				if (layout[i] != -1)
					printf("%c", layout[i] + 'a');
			}
			printf("\n");
		}
	}
}