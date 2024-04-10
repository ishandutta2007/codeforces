#include <stdio.h>

int main()
{
    int n, i = 1;
    char s[5][10] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

    scanf("%d", &n);

    while (n > i * 5) {
	n -= i * 5;
	i *= 2;
    }

    printf("%s\n", s[(n - 1) / i]);

    return 0;
}