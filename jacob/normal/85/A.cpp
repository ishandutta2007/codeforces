#include <cstdio>
using namespace std;


int main(void) {
	int n;
	scanf("%d", &n);
	if (n % 2 == 1) {
		for (int i = 0; i < 4; i++) {
			int ch = (i % 2 == 0) ? 'a' : ('a' + 5);
			if (i == 0 || i == 1) {
				for (int j = 0; j < n / 2; j++) {
					printf("%c%c", ch, ch);
					ch++;
					if (ch == 'a' + 5)
						 ch = 'a';
					if (ch == 'a' + 10)
						ch = 'a' + 5;
				}
				printf("x");
			} else {
				printf("y");
				for (int j = 0; j < n / 2; j++) {
					printf("%c%c", ch, ch);
					ch++;
					if (ch == 'a' + 5)
						ch = 'a';
					if (ch == 'a' + 10)
						ch = 'a' + 5;
				}
			}
			printf("\n");
		}
	} else {
		bool b = false;
		for (int i = 0; i < 4; i++) {
			int ch = (i % 2 == 0) ? 'a' : ('a' + 5);
			if (i == 0 || i == 1) {
				for (int j = 0; j < n / 2; j++) {
					printf("%c%c", ch, ch);
					ch++;
					if (ch == 'a' + 5)
						 ch = 'a';
					if (ch == 'a' + 10)
						ch = 'a' + 5;
				}
			} else {
				if (i % 2 == 0)
					b = !b;
				printf("%c", (b) ? 'y' : 'z');
				for (int j = 0; j < n / 2 - 1; j++) {
					printf("%c%c", ch, ch);
					ch++;
					if (ch == 'a' + 5)
						ch = 'a';
					if (ch == 'a' + 10)
						ch = 'a' + 5;
				}
				printf("%c", (!b) ? 'y' : 'z');
			}
			printf("\n");
		}
	}
	return 0;
}