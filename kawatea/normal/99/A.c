#include <stdio.h>
#include <string.h>

int main()
{
    char s1[1000], s2[1000];
    int i;

    scanf("%[^.]%*c%s", s1, s2);

    if (s1[strlen(s1) - 1] == '9') {
	puts("GOTO Vasilisa.");
    } else {
	for (i = 0; i < strlen(s1) - 1; i++) printf("%c", s1[i]);

	if (s2[0] >= '5') {
	    printf("%c\n", s1[i] + 1);
	} else {
	    printf("%c\n", s1[i]);
	}
    }

    return 0;
}