#include <stdio.h>

int main()
{
    int a[6] = {0}, b[7] = {0};
    char s[7];
    int i;

    scanf("%s", s);

    for (i = 0; i < 6; i++) {
	switch (s[i]) {
	case 'R' : a[0]++; break;
	case 'O' : a[1]++; break;
	case 'Y' : a[2]++; break;
	case 'G' : a[3]++; break;
	case 'B' : a[4]++; break;
	case 'V' : a[5]++; break;
	}
    }

    for (i = 0; i < 6; i++) b[a[i]]++;

    if (b[6] == 1 || b[5] == 1) {
	puts("1");
    } else if (b[4] == 1 || b[3] == 2) {
	puts("2");
    } else if (b[3] == 1) {
	if (b[2] == 1) {
	    puts("3");
	} else {
	    puts("5");
	}
    } else if (b[2] == 3) {
	puts("6");
    } else if (b[2] == 2) {
	puts("8");
    } else if (b[2] == 1) {
	puts("15");
    } else {
	puts("30");
    }

    return 0;
}