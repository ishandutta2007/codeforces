#include <stdio.h>
#include <string.h>

int main()
{
    char s1[3], s2[3], s3[3];
    char c1[12][3] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
    int a = 0, b = 0, c = 0, i;

    scanf("%s %s %s", s1, s2, s3);

    for (i = 0; i < 12; i++) {
	if (strcmp(s1, c1[i]) == 0) {
	    a = i;
	}
	if (strcmp(s2, c1[i]) == 0) {
	    b = i;
	}
	if (strcmp(s3, c1[i]) == 0) {
	    c = i;
	}
    }

    if (a > b) {
	int tmp = a; a = b; b = tmp;
    }
    if (a > c) {
	int tmp = a; a = c; c = tmp;
    }
    if (b > c) {
	int tmp = b; b = c; c = tmp;
    }

    if (a + 4 == b && b + 3 == c) {
	puts("major");
	return 0;
    } else if (a + 3 == b && b + 4 == c) {
	puts("minor");
	return 0;
    }

    a += 12;

    if (b + 4 == c && c + 3 == a) {
	puts("major");
	return 0;
    } else if (b + 3 == c && c + 4 == a) {
	puts("minor");
	return 0;
    }

    b += 12;

    if (c + 4 == a && a + 3 == b) {
	puts("major");
	return 0;
    } else if (c + 3 == a && a + 4 == b) {
	puts("minor");
	return 0;
    }

    puts("strange");

    return 0;
}