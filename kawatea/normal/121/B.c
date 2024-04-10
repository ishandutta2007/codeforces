#include <stdio.h>

int main()
{
    int n, k, i, j;
    char s[100001];

    scanf("%d %d", &n, &k);
    scanf("%s", s);

    for (i = 0; i < n - 1; i++) {
	if (k == 0) break;

	if (s[i] == '4' && s[i + 1] == '7') {
	    if (i % 2 == 0) {
		s[i + 1] = '4';
		k--;
	    } else {
		s[i] = '7';

		if (s[i - 1] == '4') {
		    if (k % 2 == 0) s[i] = '4';

		    k = 0;

		    break;
		}

		k--;
	    }
	}
    }

    printf("%s\n", s);

    return 0;
}