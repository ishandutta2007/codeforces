#include <stdio.h>
#include <string.h>

int main()
{
    char s1[105], s2[105], s3[105];
    int a = 0, b = 0, c = 0, i;

    fgets(s1, 105, stdin);
    fgets(s2, 105, stdin);
    fgets(s3, 105, stdin);

    for (i = 0; i < strlen(s1); i++) {
	if (s1[i] == 'a' || s1[i] == 'i' || s1[i] == 'u' || s1[i] == 'e' || s1[i] == 'o') a++;
    }

    for (i = 0; i < strlen(s2); i++) {
	if (s2[i] == 'a' || s2[i] == 'i' || s2[i] == 'u' || s2[i] == 'e' || s2[i] == 'o') b++;
    }

    for (i = 0; i < strlen(s3); i++) {
	if (s3[i] == 'a' || s3[i] == 'i' || s3[i] == 'u' || s3[i] == 'e' || s3[i] == 'o') c++;
    }

    if (a == 5 && b == 7 && c == 5) {
	puts("YES");
    } else {
	puts("NO");
    }

    return 0;
}