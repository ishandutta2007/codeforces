#include <stdio.h>
#include <string.h>

int main() {

	int n, m, i, j, k;
	int arr[100000];
	char ch[1000];
	int am = 0;

	scanf("%s", ch);
	for (i = 0; i < strlen(ch); i++) {
		if (ch[i] != 'n' && ch[i] != 'a' && ch[i] != 'e' && ch[i] != 'i'  && ch[i] != 'o' && ch[i] != 'u') {
			if (i == strlen(ch) - 1 || (ch[i + 1] != 'a' && ch[i + 1] != 'e' && ch[i + 1] != 'i' && ch[i + 1] != 'o' && ch[i+1] != 'u')){
				am = 1;
				break;
			}
		}
	}

	if (am == 1) {
		printf("NO");
	}
	else printf("YES");
}